//
// Created by ap16032 on 02/03/2018.
//

#ifndef EX3_1_VECTOR_H
#define EX3_1_VECTOR_H

#include <cmath>

namespace myproject{
    class Vector {
    public:
        Vector(); //constructor
        void setX(double); //sets X coordinate
        void setY(double); //sets Y coordinate
        void setZ(double); //sets Z coordinate
        double getX() const; //gets X coordinate
        double getY() const; //gets Y coordinate
        double getZ() const; //gets Z coordinate

        double modSqr() const; //gives squared modulus of vector
        double mod() const; //gives modulus of vector
        double dot(const Vector &v) const; //dot product
        double distance(const Vector &v) const; // Distance between 2 vectors

        void scale(double); // Scale (x,y,z) by a factor
        Vector unit(); // gives the unit vector
        Vector cross(const Vector &v) const; //gives cross product

    private:
        double x,y,z;
    };

}


#endif //EX3_1_VECTOR_H
