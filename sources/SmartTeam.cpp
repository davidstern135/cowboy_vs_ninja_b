//
// Created by david on 5/15/2023.
//

#include "SmartTeam.hpp"

namespace ariel {
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

    void SmartTeam::attack(Team *enemiesTeam) {
        if (enemiesTeam == nullptr) {
            throw std::invalid_argument("enemy team is null!");
        }
        if (enemiesTeam->stillAlive() == 0) {
            throw runtime_error("the team you are attacking is all dead!");
        }
        if (this->stillAlive() == 0) {
            throw runtime_error("you cannot attack with dead alies!");
        }
        if (!enemiesTeam->getLeader()->isAlive()) {
            enemiesTeam->setNewLeader();
        }
        if (!this->getLeader()->isAlive()) {
            this->setNewLeader();
        }
        Character *target = enemiesTeam->getTarget(this->getLeader());
        bool allCowboys = false;
        while (this->flagCheck() && !allCowboys) {
            for (unsigned i = 0; this->getTeamMembers().size() > i; i++) {

                if (!target->isAlive()) {
                    target = enemiesTeam->getTarget(this->getLeader());
                }
                if (enemiesTeam->stillAlive() == 0) {
                    return;
                }
                if (!enemiesTeam->getLeader()->isAlive())
                    enemiesTeam->setNewLeader();
                if (this->getTeamMembers().at(i)->getFlag() && this->getTeamMembers().at(i)->isAlive() &&
                    target->isAlive()) {
                    if (target->getHealth() <= 20 && target->getHealth() > 10 &&
                        i < this->getTeamMembers().size() - 1) {
                        if (Cowboy *cowboy = dynamic_cast<Cowboy *>(this->getTeamMembers().at(i))) {
                            if (Cowboy *cowboy2 = dynamic_cast<Cowboy *>(this->getTeamMembers().at(i + 1))) {
                                cowboy->shoot(target);
                                cowboy2->shoot(target);
                                cowboy->setFlag(false);
                                cowboy2->setFlag(false);
                            }
                        } else if (target->getHealth() <= 10) {
                            if (Cowboy *cowboy3 = dynamic_cast<Cowboy *>(this->getTeamMembers().at(i))) {
                                cowboy3->shoot(target);
                                cowboy3->setFlag(false);
                            }
                        } else {
                            unsigned whatPlace = this->getCloseNinja(target);
                            if (whatPlace == 20) {
                                allCowboys = true;
                            } else {
                                if (Ninja *ninja = dynamic_cast<Ninja *>(this->getTeamMembers().at(whatPlace))) {
                                    if (ninja->distance(target) < 1) {
                                        ninja->slash(target);
                                    } else {
                                        ninja->move(target);
                                        if (ninja == this->getLeader())
                                            enemiesTeam->getTarget(getLeader());
                                    }
                                    ninja->setFlag(false);
                                }
                            }
                        }
                    }
                }
            }
        }
        for (unsigned i = 0; this->getTeamMembers().size() > i; i++) {
            if (!target->isAlive()) {
                target = enemiesTeam->getTarget(this->getLeader());
            }
            if (enemiesTeam->stillAlive() == 0) {
                return;
            }
            if (!enemiesTeam->getLeader()->isAlive())
                enemiesTeam->setNewLeader();
            if (this->getTeamMembers().at(i)->getFlag() && this->getTeamMembers().at(i)->isAlive() &&
                target->isAlive()) {
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(this->getTeamMembers().at(i))) {
                    cowboy->shoot(target);
                }
            }
        }
        this->resetFlags();
    }

    unsigned SmartTeam::getCloseNinja(Character *target) {
        double minDis = std::numeric_limits<double>::max();
        unsigned whatPlace = 20;
        for (unsigned i = 0; this->getTeamMembers().size() > i; i++) {
            if (this->getTeamMembers().at(i)->isAlive() && this->getTeamMembers().at(i)->getFlag()) {
                if (Ninja *ninja = dynamic_cast<Ninja *>(this->getTeamMembers().at(i))) {
                    if (this->getTeamMembers().at(i)->distance(target) < minDis) {
                        minDis = this->getTeamMembers().at(i)->distance(target);
                        whatPlace = i;
                    }
                }
            }
        }
        return whatPlace;

    }


    void SmartTeam::resetFlags() {
        for (Character *member: this->getTeamMembers()) {
            if(member->isAlive())
            member->setFlag(true);
            else
                member->setFlag(false);
        }
    }

    bool SmartTeam::flagCheck() {
        for (Character *member: this->getTeamMembers()) {
            if (member->getFlag()) {
                return true;
            }
        }
        return false;
    }

} // ariel