//
// Created by david on 5/15/2023.
//

#include "Team.hpp"

namespace ariel {
    Team::Team() : leader(nullptr) {}

    Team::Team(Character *leader) : leader(leader) {
        if (leader == nullptr) {
            throw invalid_argument("leader is null!");
        }
        this->add(leader);
        this->leader = leader;
        this->leader->setPlayingStatus(true);
    }

    Team::~Team() {
        for (Character* member : TeamMembers) {
            delete member;
        }
    }
    vector<Character*>& Team::getTeamMembers()  {
        return TeamMembers;
    }



    void Team::add(Character *TeamMate) {
        if (TeamMate->getPlayingStatus())
            throw runtime_error("The character is already in a team");
        else if (this->TeamMembers.size() == 10) {
            throw runtime_error("the team is full.");
        } else {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(TeamMate))
                this->TeamMembers.insert(TeamMembers.begin(), TeamMate);
            else {
                this->TeamMembers.push_back(TeamMate);
            }
            TeamMate->setPlayingStatus(true);
        }
    }

    void Team::setLeader(Character *leader) {
        this->leader = leader;
    }

    void Team::setNewLeader() {
        if (this->stillAlive() == 0) {
            return;
        }
        double minDis = std::numeric_limits<double>::max();
        unsigned whatPlace = 0;
        for (unsigned i = 0; i < this->TeamMembers.size(); i++) {
            if (this->TeamMembers.at(i)->isAlive()) {
                if (this->TeamMembers.at(i)->distance(this->leader) < minDis) {
                    minDis = this->TeamMembers.at(i)->distance(this->leader);
                    whatPlace = i;
                }
            }
        }
        this->leader = this->TeamMembers.at(whatPlace);
    }
    Character* Team::getLeader() {
        return this->leader;
    }
    Character *Team::getTarget(Character *leader) {
        double minDis = std::numeric_limits<double>::max();
        unsigned whatPlace = 0;
        for (unsigned i = 0; this->TeamMembers.size() > i; i++) {
            if (this->TeamMembers.at(i)->isAlive()) {
                if (this->TeamMembers.at(i)->distance(leader) < minDis) {
                    minDis = this->TeamMembers.at(i)->distance(leader);
                    whatPlace = i;
                }
            }
        }
        return this->TeamMembers.at(whatPlace);

    }

    void Team::attack(Team *enemiesTeam) {
        if (enemiesTeam == nullptr) {
            throw std::invalid_argument("enemy team is null!");
        }
        if (enemiesTeam->stillAlive() == 0) {
            throw runtime_error("the team you are attacking is all dead!");
        }
        if (this->stillAlive() == 0) {
            throw runtime_error("you cannot attack with dead alies!");
        }
        if (!enemiesTeam->leader->isAlive()) {
            enemiesTeam->setNewLeader();
        }
        if (!this->leader->isAlive()) {
            this->setNewLeader();
        }
        Character *target = enemiesTeam->getTarget(this->leader);
        for (unsigned i = 0; this->TeamMembers.size() > i; i++) {

            if (!target->isAlive()) {
                target = enemiesTeam->getTarget(this->leader);
            }
            if (enemiesTeam->stillAlive() == 0) {
                return;
            }
            if (this->TeamMembers.at(i)->isAlive() && target->isAlive()) {
                if (!enemiesTeam->leader->isAlive())
                    enemiesTeam->setNewLeader();
                if (Cowboy *cowboy = dynamic_cast<Cowboy *>(this->TeamMembers.at(i))) {
                    cowboy->shoot(target);
                } else {
                    if (Ninja *ninja = dynamic_cast<Ninja *>(this->TeamMembers.at(i))) {
                        if (ninja->distance(target) < 1) {
                            ninja->slash(target);
                        } else {
                            ninja->move(target);
                            if (ninja == this->leader)
                                enemiesTeam->getTarget(leader);

                        }
                    }
                }
                if (!enemiesTeam->leader->isAlive())
                    enemiesTeam->setNewLeader();
            }
        }
    }


    int Team::stillAlive() {
        int numOfTeamMembersAlive = 0;
        for (unsigned i = 0; this->TeamMembers.size() > i; i++) {
            if (this->TeamMembers.at(i)->isAlive())
                numOfTeamMembersAlive++;
        }
        return numOfTeamMembersAlive;
    }

    void Team::print() {
        string out = "we got " + to_string(this->TeamMembers.size()) + " team members: \n";
        for (unsigned i = 0; i < this->TeamMembers.size(); i++) {
            out += this->TeamMembers.at(i)->print();
            if (i < this->TeamMembers.size() - 1)
                out += "\n";
        }
        cout<<out<<endl;

    }


} // ariel