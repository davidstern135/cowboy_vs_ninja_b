//
// Created by david on 5/15/2023.
//

#ifndef CPP_COWBOY_HPP
#define CPP_COWBOY_HPP
#include "Character.hpp"
#include "Point.hpp"
#include <iostream>
namespace ariel {

    class Cowboy : public Character {
        int bulletsLeft;
    public:
        Cowboy(string name, Point location);
        void shoot(Character* enemy);
        bool hasboolets();
        void reload();
//        string print() const override;

    };

} // ariel

#endif //CPP_COWBOY_HPP
