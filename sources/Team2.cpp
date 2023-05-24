//
// Created by david on 5/15/2023.
//

#include "Team2.hpp"

namespace ariel {
    Team2::Team2(Character* leader): Team(leader){    }
//    Team2::~Team2() {
//        for(unsigned i;i<this->getTeamMembers().size();i++){
//            delete(&(this->getTeamMembers().at(i)));
//        }
//    }

    void Team2::add(Character* TeamMate) {
        if (TeamMate->getPlayingStatus())
            throw runtime_error("The character is already in a team");
        else if (this->getTeamMembers().size() == 10) {
            throw runtime_error("the team is full.");
        }
        else {
                this->getTeamMembers().push_back(TeamMate);
            }
            TeamMate->setPlayingStatus(true);
        }
} // ariel