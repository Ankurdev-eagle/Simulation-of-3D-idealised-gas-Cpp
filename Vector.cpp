//
// Created by ap16032 on 02/03/2018.
//
#include <iostream>
#include "Vector.h"
#include <cmath>

physics::Vector::Vector() : x(0), y(0), z(0) {;} //constructor
// constructor initialises all coordinates to 0 by default

/* Setting x,y,z coordinates */
void physics::Vector::setX(double a) { x=a;}
void physics::Vector::setY(double a) { y=a;}
void physics::Vector::setZ(double a) { z=a;}

/* Getting x,y,z coordinates */
double myproject::Vector::getX() const { return x;}
double myproject::Vector::getY() const { return y;}
double myproject::Vector::getZ() const { return z;}

double myproject::Vector::modSqr() const
{
    return (x*x + y*y + z*z); //gives squared modulus of vector
}

double myproject::Vector::mod() const
{
    return (sqrt(myproject::Vector::modSqr())); // gives modulus of vector
}

double myproject::Vector::dot(const myproject::Vector &v) const
{
    /*This method gives the dot product of the vector it
      is being called on and the vector in argument */
    return v.getX()*x + v.getY()*y + v.getZ()*z;
}

double myproject::Vector::distance(const Vector &v) const
{
    //Gives Distance between 2 vectors
    Vector Vdiff;
    /*Creating and setting new Vector object to the
      difference between the two vectors */
    Vdiff.setX(x-v.getX());
    Vdiff.setY(y-v.getY());
    Vdiff.setZ(z-v.getZ());
    return Vdiff.mod(); //returns modulus of Vdiff vector
}

void myproject::Vector::scale(double f)
{
    //Scaling (x,y,z) by factor f
    x *= f;
    y *= f;
    z *= f;
}

myproject::Vector myproject::Vector::unit() //returns unit vector
{
    myproject::Vector v;
    v.setX(x);
    v.setY(y);
    v.setZ(z);
    double factor = 1.0/v.mod();  //dividing by modulus of vector
    v.scale(factor);
    return v;
}

myproject::Vector myproject::Vector::cross(const Vector &v) const
{
    // Gives cross product --> u x v = u.cross(v)
    //calculating cross product components
    double wx = y*v.getZ()-z*v.getY();
    double wy = z*v.getX() - x*v.getZ();
    double wz = x*v.getY() - y*v.getX();

    Vector w; //creates cross product vector
    w.setX(wx);
    w.setY(wy);
    w.setZ(wz);
    return w;
}