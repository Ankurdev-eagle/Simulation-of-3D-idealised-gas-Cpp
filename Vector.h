//
// Created by ap16032 on 02/03/2018.
//

#ifndef EX3_1_VECTOR_H
#define EX3_1_VECTOR_H

#include <cmath>

namespace physics{
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
        /*** Overloading Operators ***/
        // Addition, Subtraction and Inversion of vectors //
        Vector operator+(const Vector &v1)  //overloading operator +
        {
            Vector v0(*this);  //creating a copy vector v0
            //updating copy vector and adding components
            v0.x += v1.x;
            v0.y += v1.y;
            v0.z += v1.z;
            return v0;
        }

        Vector operator-(const Vector &v1)  //overloading operator - with object argument
        {
            Vector v0(*this);  //creating a copy vector v0
            //updating copy vector and subtracting components
            v0.x = v0.x - v1.x;
            v0.y = v0.y - v1.y;
            v0.z = v0.z - v1.z;
            return v0;
        }

        Vector operator-()  //overloading operator - (for inversion of vector)
        {
            Vector v0(*this);  //creating a copy vector v0
            //updating copy vector and inverting components
            v0.x = -v0.x;
            v0.y = -v0.y;
            v0.z = -v0.z;
            return v0;
        }

    private:
        double x,y,z;
    };

}


#endif //EX3_1_VECTOR_H
