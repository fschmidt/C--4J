/*
   Simple Unit Test for type RationalNumber
*/

#include <stdio.h>
#include <assert.h>

#include "rationalnumber.h"
#include "RationalNumberArray.h"

void testRationalNumberArray();
void myTestCallbackFunction(RationalNumberArray *data);

int main() {

    printf("Performing unit tests for RationalNumber...");
    fflush(stdout);

    /* Part 1 - RationalNumber data type */
    RationalNumber  n1 = { 3, 4 },
            n2 = { 6, 4 },
            n3 = { 3, 2 },
            n4 = { -9, -6 },
            n5 = { 9, -6 },
            n6 = { 9, 4 },
            n0 = { 0, 4 },
            nn = { 4, 0 };

    assert( rnIsValid(n0) );
    assert( !rnIsValid(nn) );
    assert( rnIsNaN(nn) );

    assert( rnEqual( n2, n3) );
    assert( rnEqual( rnAdd(n1,n1), n2) );
    assert( rnEqual( n2,n4) );
    assert( !rnEqual( n4,n5) );
    assert( rnLessThan( n5,n3) );

    RationalNumber t1 = rnAdd(n1,n2);
    RationalNumber t2 = rnDiv(n3,n3);
    RationalNumber t3 = rnDiv(n2,n2);
    RationalNumber t4 = rnDiv(n6,n0);

    assert( rnEqual(t1, n6) );
    assert( rnEqual(t2, t3) );
    assert( rnIsNaN(t4) );

    printf("RN successful!\n");

    testRationalNumberArray();

    return 0;
}

void testRationalNumberArray(){

    RationalNumber
            n1 = { 3, 4 },
            n2 = { 6, 4 },
            n3 = { 3, 2 },
            n4 = { -9, -6 },
            n5 = { 9, -6 },
            n6 = { 9, 4 },
            n7 = { 0, 4 },
            n8 = { 4, 0 };

    // Create a RationalNumberArray and check size and capazity
    RationalNumberArray* myAr = rnaCreate(5);
    assert(rnaSize(myAr)==0);
    assert(rnaCapacity(myAr)==5);

    // add some values
    rnaAdd(myAr, &n1);
    rnaAdd(myAr, &n2);
    rnaAdd(myAr, &n3);
    rnaAdd(myAr, &n4);

    // check new size and capacity
    assert(rnaSize(myAr)==4);
    assert(rnaCapacity(myAr)==5);

    rnaAdd(myAr, &n5);
    rnaAdd(myAr, &n6);
    rnaAdd(myAr, &n7);

    assert(rnaSize(myAr)==7);
    assert(rnaCapacity(myAr)==10);


    printf("\nNominator: %d\n\n",(rnaGet(myAr, 0))->nominator);
    printf("\nNominator: %d\n\n",(rnaGet(myAr, 5))->nominator);
    printf("\nNominator: %d\n\n",(rnaGet(myAr, 6))->nominator);

    // check whether the added values are correct
    assert((rnaGet(myAr, 0) -> nominator == n1.nominator) && (rnaGet(myAr, 0) -> denominator == n1.denominator));
    assert((rnaGet(myAr, 5) -> nominator == n6.nominator) && (rnaGet(myAr, 5) -> denominator == n6.denominator));
    assert((rnaGet(myAr, 6) -> nominator == n7.nominator) && (rnaGet(myAr, 6) -> denominator == n7.denominator));

    // ovveride a value
    rnaSet(myAr, &n8, 2);

    // check the overridden value
    assert((rnaGet(myAr, 2) -> nominator == n8.nominator) && (rnaGet(myAr, 2) -> denominator == n8.denominator));

    // produce an error
    rnaGet(myAr, 9);

    // set an errorCallback
    rnaSetErrorCallback(myAr, &myTestCallbackFunction);

    // produce another error
    rnaGet(myAr, 9);

    // set a value outside of the current capacity
    rnaSet(myAr, &n8, 200);

    // check the value
    assert((rnaGet(myAr, 200) -> nominator == n8.nominator) && (rnaGet(myAr, 200) -> denominator == n8.denominator));

    // check the new size
    printf("\nSize: %d\n\n",(rnaSize(myAr)));
    assert(rnaSize(myAr)==201);

    // check whether capacity has been increased correctly
    printf("\nCapacity: %d\n\n",(rnaCapacity(myAr)));
    assert(rnaCapacity(myAr)==320);

    rnaResize(myAr, 10);
    assert(rnaSize(myAr) == 10);
    assert(rnaCapacity(myAr) == 10);

    rnaRemove(myAr, 5, 5);
    printf("\nNominators: %d ; %d\n\n",rnaGet(myAr, 5)->nominator, n7.nominator);
    assert(rnEqual(*rnaGet(myAr, 5), n7));

    rnaResize(myAr, 100);
    assert(rnaSize(myAr) == 9);
    assert(rnaCapacity(myAr) == 100);

    printf("RNA successful!\n");

}

void myTestCallbackFunction(RationalNumberArray *data){
    printf("Error Callback");
}
