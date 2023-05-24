//
// Created by david on 5/15/2023.
//

#include "Ninja.hpp"

namespace ariel {
    Ninja::Ninja(string name, int HPNinja, Point location, int speed)
            :Character(name, location, HPNinja), speed(speed) {}

    void Ninja::move(Character* enemy) {
        this->setLocation(Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed));
    }


    void Ninja::slash(Character* enemy) {
        if(!this->isAlive()||!enemy->isAlive()){
            throw runtime_error("you cannot attack dead enemies if you are dead or they are dead");
        }
        if(this==enemy){
            throw runtime_error("you cannot harm yourself");
        }
        if(this->distance(enemy)<1) {
            enemy->hit(40);
        }
    }

    int Ninja::getSpeed(){
        return this->speed;
    }







} // ariel