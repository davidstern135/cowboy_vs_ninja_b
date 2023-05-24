//
// Created by david on 5/15/2023.
//

#ifndef CPP_CHARACTER_HPP
#define CPP_CHARACTER_HPP
#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"

using namespace std;
namespace ariel {
    class Character {
        string name;
        int health;
        Point location;
        bool playingStatus;
        bool smartFlag;
    public:
        Character(string CharName, Point &Charlocation, int CharHP);
        Character(Character& other);
        virtual ~Character() = default;

        bool getFlag();
        void setFlag(bool flag);
        void setPlayingStatus (bool Stat);
        bool getPlayingStatus();
        bool isAlive();
        double distance( Character* other);
        void hit(int hurtPoint);
        string getName();
        Point getLocation();
        void setLocation(const Point &other);
        virtual string print()const;
        Character& operator=(const Character& other);
        int getHealth();


        Character(Character&& ) noexcept;
        Character& operator = (Character&&) noexcept;


    };
}


#endif //CPP_CHARACTER_HPP
