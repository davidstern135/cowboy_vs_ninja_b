//
// Created by david on 5/15/2023.
//

#ifndef CPP_SMARTTEAM_HPP
#define CPP_SMARTTEAM_HPP
#include "Team.hpp"

namespace ariel {

    class SmartTeam:public Team{
    public:
        SmartTeam(Character* leader);
        void attack(Team* enemies);
        unsigned getCloseNinja(Character* target);
        bool flagCheck();
        void resetFlags();
    };

} // ariel

#endif //CPP_SMARTTEAM_HPP
