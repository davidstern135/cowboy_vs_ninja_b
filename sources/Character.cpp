//
// Created by david on 5/15/2023.
//

#include "Character.hpp"
#include <iostream>

using namespace std;
namespace ariel {
    bool Character::isAlive() {
        if (this->health>0){
            return true;
        }
        else
        return false;
    }

    Character::Character(string CharName, Point &Charlocation, int CharHP)
            : name(CharName), location(Charlocation), health(CharHP) {
        this->playingStatus=0;
        this->smartFlag=true;
    }

    Character::Character(Character &other)
            : name(other.getName()), location(other.getLocation()), health(other.health) {
        this->playingStatus=0;
        this->smartFlag=true;
    }
    bool Character::getFlag(){
        return this->smartFlag;
    }
    void Character::setFlag(bool flag){
        this->smartFlag=flag;
    }
    double Character::distance(Character * other) {
        return this->location.distance(other->location);
    }

    void Character::hit(int hurtPoint){
        if(hurtPoint<=0){
            throw invalid_argument("cannot attack with o or less hurtpoints");
        }
        else if(this->health<hurtPoint){
            this->health=0;
        }
        else this->health-=hurtPoint;
    }
    int Character::getHealth(){
        return this->health;
    }
    string Character::getName(){
        return this->name;
    }

    Point Character::getLocation(){

        return this->location;
    }
    void Character::setLocation(const ariel::Point &other) {
        this->location=other;
    }

    string Character::print()const{
        return "name:"+ this->name+" location:"+this->location.print()+" health:" + to_string(this->health);
    }
    Character& Character::operator=(const Character& other){
        if(this==&other){
            return *this;
        }
        this->name=other.name;
        this->location=other.location;
        this->health=other.health;
        return *this;
    }
    void Character::setPlayingStatus(bool stat) {
        this->playingStatus=stat;
    }
    bool Character::getPlayingStatus(){
        return this->playingStatus;
    }

}