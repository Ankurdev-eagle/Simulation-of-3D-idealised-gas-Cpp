//
// Created by Eagle on 3/4/2018.
//
#include <iostream>
#include <cmath>
#include "functions.h"
#include "Vector.h"
using namespace std;
bool testFloat(double value, double test, double p)
{
    double diff = value - test;
    if (fabs(diff)<p)  // checks if absolute value of difference is less than p
        return true;
    else
        return false;
}

bool test1()                            // returns true if all tests are a success
{
    bool b;
    myproject::Vector obj1;     // creates new object in Vector class
    const double acc = 0.0001; // sets accuracy
    if((testFloat(0,obj1.getX(),acc)&&
            testFloat(0,obj1.getY(),acc) &&
            testFloat(0,obj1.getZ(),acc))== true)  // condition checks if all initial values are (0,0,0)
        b = true;
    else
        b = false;

    /* setting X,Y,Z to (10,20,30) using the object */
    obj1.setX(10);
    obj1.setY(20);
    obj1.setZ(30);

    if((b &&                                      // true is previous test was success
        testFloat(10.0,obj1.getX(),acc)&&
        testFloat(20.0,obj1.getY(),acc) &&
        testFloat(30.0,obj1.getZ(),acc))== true) // condition checks if values are set to (10, 20, 30)
        return true;
    else
        return false;

}

bool testModulus()
{
    myproject::Vector obj2;
    // Creating new object initialised to (1,2,3)
    obj2.setX(1);
    obj2.setY(2);
    obj2.setZ(3);
    double modulus, modulusSqr;
    // explicitly calculating modulus of obj2 vector
    modulusSqr = 1*1 + 2*2 + 3*3;
    modulus = sqrt(modulusSqr);
    const double acc = 0.0001;
    //Checking if both mod and modSqr methods are correct
    if ((testFloat(modulusSqr,obj2.modSqr(),acc)&&
            testFloat(modulus,obj2.mod(),acc))== true)
        return true;
    else
        return false;
}

bool testDistance()     //testing distance method
{
    myproject::Vector v1;
    // Creating new object v1 initialised to (1,2,3)
    v1.setX(1);
    v1.setY(2);
    v1.setZ(3);

    myproject::Vector v2;
    // Creating new object v2 initialised to (3,2,1)
    v2.setX(3);
    v2.setY(2);
    v2.setZ(1);
    const double acc = 0.0001; // sets accuracy
    const double actual_dist = 2.828427; //true distance between v1 and v2
    double d = v1.distance(v2); // calculating distance
    //comparing calculated and true distance
    if (testFloat(actual_dist,d,acc)==true)
        return true;
    else
        return false;
}

bool testDot()   //Testing the Dot method
{
    myproject::Vector v1;
    // Creating new object v1 initialised to (1,0,1)
    v1.setX(1);
    v1.setY(0);
    v1.setZ(1);

    myproject::Vector v2;
    // Creating new object v2 initialised to (0,1,0)
    v2.setX(0);
    v2.setY(1);
    v2.setZ(0);
    const double acc = 0.0001; // sets accuracy
    bool dot1, dot2;
    if (testFloat(0,v1.dot(v2),acc)==true) //checking if v1.v2 is 0
        dot1 = true;
    else
        dot1 = false;

    myproject::Vector v3;
    // Creating new object v3 initialised to (1,1,1)
    v3.setX(1);
    v3.setY(1);
    v3.setZ(1);

    myproject::Vector v4;
    // Creating new object v4 initialised to (0,1,1)
    v4.setX(0);
    v4.setY(1);
    v4.setZ(1);

    if (testFloat(2,v3.dot(v4),acc)==true)  //checking if v3.v4 is 2
        dot2 = true;
    else
        dot2 = false;

    if(dot1&&dot2 == true)  //checking if both dot product tests were a success
        return true;
    else
        return false;
}

bool testScale()
{
    const double acc = 0.0001; // sets accuracy
    myproject::Vector v;
    // Creating new object v initialised to (1,1,1)
    v.setX(1);
    v.setY(1);
    v.setZ(1);
    v.scale(3); //scaling by factor 3
    //checking if x,y,z all equals 3
    if ((testFloat(3,v.getX(),acc) &&
            testFloat(3,v.getY(),acc) &&
            testFloat(3,v.getZ(),acc)) == true)
        return true;
    else
        return false;
}

bool testUnit()
{
    myproject::Vector v1;
    // Creating new object v1 initialised to (3,3,3)
    v1.setX(3);
    v1.setY(3);
    v1.setZ(3);
    myproject::Vector v2;
    v2 = v1.unit(); // v2 equals unit vector of v1
    bool case1,case2;
    //checking if modulus of v2 is 1
    if (v2.mod()== 1)
        case1 = true;
    else
        case1 = false;
    //checking if v1.v2 equals modulus of v1
    if (v1.dot(v2) == v1.mod())
        case2 = true;
    else
        case2 = false;
    //checking if both tests succeeded
    if ((case1 && case2)== true)
        return true;
    else
        return false;
}

bool testCross()   //testing the cross product
{
    myproject::Vector v1;
    // Creating new object v1 initialised to (1,0,0)
    v1.setX(1);
    v1.setY(0);
    v1.setZ(0);
    myproject::Vector v2;
    // Creating new object v2 initialised to (0,1,0)
    v2.setX(0);
    v2.setY(1);
    v2.setZ(0);
    myproject::Vector v3;
    // Creating new object v3 initialised to (0,0,1)
    v3.setX(0);
    v3.setY(0);
    v3.setZ(1);

    myproject::Vector v4,v5,v6;
    v4 = v1.cross(v2); //evaluating v1 x v2
    v5 = v2.cross(v3); //evaluating v2 x v3
    v6 = v3.cross(v1); //evaluating v3 x v1

    /* we know v4 = (0,0,1)
               v5 = (1,0,0)
               v6 = (0,1,0)
       So, distance between v4 and v3 equals zero
       Similarly for v5, v6 */
    // checking if above rule holds
    if(v4.distance(v3)==0 &&
            v5.distance(v1)==0 &&
            v6.distance(v2)==0)
        return true;
    else
        return false;
}
