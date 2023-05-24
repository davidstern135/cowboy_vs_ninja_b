//
// Created by david on 5/15/2023.
//

#ifndef CPP_NINJA_HPP
#define CPP_NINJA_HPP
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
namespace ariel {

    class Ninja:public Character {
        int speed;
    public:
        Ninja(string name, int HPNinja, Point location, int speed);
        void move(Character* enemy);
        void slash(Character* enemy);
        int getSpeed();
    };




} // ariel

#endif //CPP_NINJA_HPP
