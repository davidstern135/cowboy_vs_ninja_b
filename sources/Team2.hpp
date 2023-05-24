//
// Created by david on 5/15/2023.
//

#ifndef CPP_TEAM2_HPP
#define CPP_TEAM2_HPP
#include "Team.hpp"
namespace ariel {

    class Team2: public Team{
        vector<Character*> TeamMembers;
    public:
        Team2(Character *leader);
//        ~Team2();
        void add(Character* TeamMate);
//        int stillAlive();

    };

} // ariel

#endif //CPP_TEAM2_HPP
