//
// Created by david on 5/15/2023.
//

#include "Cowboy.hpp"
#include <iostream>


namespace ariel {
    Cowboy::Cowboy(string name, Point location) : Character(name, location, 110), bulletsLeft(6) {}

    void Cowboy::shoot(Character *enemy) {
        if(!this->isAlive()||!enemy->isAlive()){
            throw runtime_error("you cannot attack dead enemies if you are dead or they are dead");
        }
        if(this==enemy){
            throw runtime_error("you cannot harm yourself");
        }
        if(this->hasboolets()){
            enemy->hit(10);
            this->bulletsLeft-=1;
            }
        else{
            this->reload();
        }
    }

    bool Cowboy::hasboolets() {
        if (this->bulletsLeft > 0)
            return true;
        else return false;
    }

    void Cowboy::reload() {
        if(!this->isAlive()){
            throw runtime_error("cannot reload when your dead");
        }
        this->bulletsLeft=6;
    }

//    string Cowboy::print() const{
//        return "fix cowboy print";
//    }
} // ariel