//
// Created by david on 5/15/2023.
//

#ifndef CPP_TEAM_HPP
#define CPP_TEAM_HPP
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include <iostream>
#include <string>
#include <vector>
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

namespace ariel {

    class Team {
        Character* leader;
//    protected:
        vector<Character*> TeamMembers;
    public:
        Team();
        Team(Character* leader);
        virtual ~Team();
        void setLeader(Character* leader);
        void setNewLeader();
        void add(Character* newMember);
        void attack(Team* enemies);
        Character* getTarget(Character* leader);
        Character* getLeader();
        int stillAlive();
        void print();
        vector<Character*>& getTeamMembers();
        Team (Team&) = delete;
        Team (Team&&) noexcept = delete;
        Team& operator = (const Team&) = delete;
        Team& operator = (Team&&) noexcept = delete;
    };



} // ariel

#endif //CPP_TEAM_HPP
