//
// Created by david on 5/15/2023.
//
#include "Point.hpp"
#include <iostream>
#include <string>


using namespace std;
namespace ariel {
    Point::Point() {
        this->paramX = 0;
        this->paramY = 0;
    }

    Point::Point(double parX, double parY) : paramX(parX), paramY(parY) {};

    double Point::distance( Point other) {
        return sqrt(pow((this->paramX - other.paramX), 2) + pow((this->paramY - other.paramY), 2));

    }

    string Point::print()const {
        return "("+to_string(this->getX())+","+to_string(this->getY())+")";
    }

    Point Point::moveTowards(Point srcP, Point desP, double distance) {
        if (distance < 0)
            throw invalid_argument("distance cannot be negative!");

        double srcToDes = srcP.distance(desP);
        if (srcToDes <= distance)
            return desP;

        double ratioX = desP.getX() - srcP.getX();
        double ratioY = desP.getY() - srcP.getY();
        double ratio = distance / srcToDes;
        double newX = srcP.getX() + ratio * ratioX;
        double newY = srcP.getY() + ratio * ratioY;
        return Point(newX, newY);
    }

    double Point::getX()const {
        return this->paramX;
    }

    double Point::getY()const {
        return this->paramY;
    }
}
