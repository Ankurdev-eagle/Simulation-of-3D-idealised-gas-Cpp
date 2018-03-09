#include <iostream>
#include "Vector.h"
#include "functions.h"
using namespace std;
int main() {

    bool t1 = test1();
    if (t1 == true)   //checks if test1 was a success
        cout << "Test 1 SUCCESS" << endl;
    else
        cout << "Test 1 FAILED" <<endl;

    if (testModulus()== true) // Testing the Mod and ModSqr methods
        cout << "Test Modulus : SUCCESS" <<endl;
    else
        cout << "Test Modulus : FAILED"<<endl;

    if (testDistance()== true) // Testing the distance method
        cout << "Test Distance : SUCCESS" <<endl;
    else
        cout << "Test Distance : FAILED"<<endl;

    if (testDot()== true) // Testing the dot method
        cout << "Test Dot : SUCCESS" <<endl;
    else
        cout << "Test Dot : FAILED"<<endl;

    if (testScale()== true) // Testing the scale method
        cout << "Test Scale : SUCCESS" <<endl;
    else
        cout << "Test Scale : FAILED"<<endl;

    if (testUnit()== true) // Testing the Unit method
        cout << "Test Unit : SUCCESS" <<endl;
    else
        cout << "Test Unit : FAILED"<<endl;

    if (testCross()== true) // Testing the Cross product method
        cout << "Test Cross : SUCCESS" <<endl;
    else
        cout << "Test Cross : FAILED"<<endl;
}