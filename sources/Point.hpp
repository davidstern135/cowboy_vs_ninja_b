//
// Created by david on 5/15/2023.
//

#ifndef CPP_POINT_HPP
#define CPP_POINT_HPP
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

namespace ariel{
    class Point {
        double paramX;
        double paramY;

    public:
        Point();
        Point(double paX,double paY);
        double distance( Point other);
        string print()const;
        static Point moveTowards(Point srcP, Point desP,double distance);
        double getX()const;
        double getY()const;
    };
}


#endif //COWBOY_VS_NINJA_A_MAIN_POINT_HPP
