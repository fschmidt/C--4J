/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>
#include <iostream>
#include "rationalnumber.h"
//#include "RationalNumberArray.h"

//void testRationalNumberArray();
//void myTestCallbackFunction(RationalNumberArray *data);

using namespace std;

int main() {

    printf("Performing unit tests for RationalNumber...");
    fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber rn3_4 ( 3, 4 );
    RationalNumber rn6_4 ( 6, 4 );
    RationalNumber rn3_2 ( 3, 2 );
    RationalNumber rnm9_m6 ( -9, -6 );
    RationalNumber rn9_m6 ( 9, -6 );
    RationalNumber rn9_4 ( 9, 4 );
    RationalNumber rn0_4 ( 0, 4 );
    RationalNumber nn ( 4, 0 );

    assert( rn3_4.isValid() );
    assert( !nn.isValid() );
    assert( nn.isNaN() );

    assert( rn6_4.equal(rn3_2) );
    assert( rn3_4.add(rn3_4).equal(rn6_4) );
    assert( (rn3_4 + rn3_4).equal(rn6_4) );
    assert( !rnm9_m6.equal(rn9_m6) );
    assert( rn9_m6.lessThan(rn3_2) );
    RationalNumber mrn = rn3_4.add(rn3_4.mul(rn3_2));
    RationalNumber res = rn3_4 + rn3_4 * rn3_2 ;
    cout << "\n" << res << "\n";
    assert( res.nominator()==15 && res.denominator() == 8 );


    RationalNumber t1 = rn3_4.add(rn6_4);
    RationalNumber t2 = rn3_2.div(rn3_2);
    RationalNumber t3 = rn6_4.div(rn6_4);
    RationalNumber t4 = rn9_4.div(rn0_4);

    assert( t1.equal(rn9_4) );
    assert( t2.equal(t3) );
    assert( t4.isNaN() );

    printf("RN successful!\n");

    //testRationalNumberArray();

    return 0;
}

//void testRationalNumberArray(){

//    RationalNumber
//            n1 = { 3, 4 },
//            n2 = { 6, 4 },
//            n3 = { 3, 2 },
//            n4 = { -9, -6 },
//            n5 = { 9, -6 },
//            n6 = { 9, 4 },
//            n7 = { 0, 4 },
//            n8 = { 4, 0 };

//    // Create a RationalNumberArray and check size and capazity
//    RationalNumberArray* myAr = rnaCreate(5);
//    assert(rnaSize(myAr)==0);
//    assert(rnaCapacity(myAr)==5);

//    // add some values
//    rnaAdd(myAr, &n1);
//    rnaAdd(myAr, &n2);
//    rnaAdd(myAr, &n3);
//    rnaAdd(myAr, &n4);

//    // check new size and capacity
//    assert(rnaSize(myAr)==4);
//    assert(rnaCapacity(myAr)==5);

//    rnaAdd(myAr, &n5);
//    rnaAdd(myAr, &n6);
//    rnaAdd(myAr, &n7);

//    assert(rnaSize(myAr)==7);
//    assert(rnaCapacity(myAr)==10);


//    printf("\nNominator: %d\n\n",(rnaGet(myAr, 0))->nominator);
//    printf("\nNominator: %d\n\n",(rnaGet(myAr, 5))->nominator);
//    printf("\nNominator: %d\n\n",(rnaGet(myAr, 6))->nominator);

//    // check whether the added values are correct
//    assert((rnaGet(myAr, 0) -> nominator == n1.nominator) && (rnaGet(myAr, 0) -> denominator == n1.denominator));
//    assert((rnaGet(myAr, 5) -> nominator == n6.nominator) && (rnaGet(myAr, 5) -> denominator == n6.denominator));
//    assert((rnaGet(myAr, 6) -> nominator == n7.nominator) && (rnaGet(myAr, 6) -> denominator == n7.denominator));

//    // ovveride a value
//    rnaSet(myAr, &n8, 2);

//    // check the overridden value
//    assert((rnaGet(myAr, 2) -> nominator == n8.nominator) && (rnaGet(myAr, 2) -> denominator == n8.denominator));

//    // produce an error
//    rnaGet(myAr, 9);

//    // set an errorCallback
//    rnaSetErrorCallback(myAr, &myTestCallbackFunction);

//    // produce another error
//    rnaGet(myAr, 9);

//    // set a value outside of the current capacity
//    rnaSet(myAr, &n8, 200);

//    // check the value
//    assert((rnaGet(myAr, 200) -> nominator == n8.nominator) && (rnaGet(myAr, 200) -> denominator == n8.denominator));

//    // check the new size
//    printf("\nSize: %d\n\n",(rnaSize(myAr)));
//    assert(rnaSize(myAr)==201);

//    // check whether capacity has been increased correctly
//    printf("\nCapacity: %d\n\n",(rnaCapacity(myAr)));
//    assert(rnaCapacity(myAr)==320);

//    rnaResize(myAr, 10);
//    assert(rnaSize(myAr) == 10);
//    assert(rnaCapacity(myAr) == 10);

//    rnaRemove(myAr, 5, 5);
//    printf("\nNominators: %d ; %d\n\n",rnaGet(myAr, 5)->nominator, n7.nominator);
//    assert(rnEqual(*rnaGet(myAr, 5), n7));

//    rnaResize(myAr, 100);
//    assert(rnaSize(myAr) == 9);
//    assert(rnaCapacity(myAr) == 100);

//    printf("RNA successful!\n");

//}

//void myTestCallbackFunction(RationalNumberArray *data){
//    printf("Error Callback");
//}
