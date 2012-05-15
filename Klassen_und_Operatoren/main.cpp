/*
   Simple Unit Test for type RationalNumber
*/

#include <assert.h>
#include <iostream>
#include "rationalnumber.h"
#include "RationalNumberArray.h"

void testRationalNumberArray();
//void myTestCallbackFunction(RationalNumberArray *data);

using namespace std;
using namespace rnum;

int main() {

    cout << "Performing unit tests for RationalNumber...\n";

    /* Part 1 - RationalNumber data type */
    RationalNumber rn3_4 ( 3, 4 );
    RationalNumber rn6_4 ( 6, 4 );
    RationalNumber rn3_2 ( 3, 2 );
    RationalNumber rnm9_m6 ( -9, -6 );
    RationalNumber rn9_m6 ( 9, -6 );
    RationalNumber rn9_4 ( 9, 4 );
    RationalNumber rn0_4 ( 0, 4 );
    RationalNumber rn4_0 ( 4, 0);

    assert( rn3_4.isValid() );
    assert( !rn4_0.isValid() );
    assert( rn4_0.isNaN() );

    assert( rn6_4.equal(rn3_2) );
    assert( rn3_4.add(rn3_4).equal(rn6_4) );
    assert( (rn3_4 + rn3_4).equal(rn6_4) );
    assert( !rnm9_m6.equal(rn9_m6) );
    assert( rn9_m6.lessThan(rn3_2) );

    RationalNumber erg(15,8);

    assert( rn3_4 + rn3_4 * rn3_2 == erg );


    RationalNumber t1 = rn3_4.add(rn6_4);
    RationalNumber t2 = rn3_2.div(rn3_2);
    RationalNumber t3 = rn6_4.div(rn6_4);
    RationalNumber t4 = rn9_4.div(rn0_4);

    assert( t1.equal(rn9_4) );
    assert( t2.equal(t3) );
    assert( t4.isNaN() );

    // test negating
    RationalNumber rnm3_4(-3,4);
    assert(-rn3_4 == rnm3_4);

    //test copy
    assert(rn3_4 == RationalNumber(rn3_4));

    assert(RationalNumber() == RationalNumber(RationalNumber()));

    assert(rn6_4 == (rn3_4 += rn3_4));

    // test rn und int
    RationalNumber rn7_1(7,1);

    assert((7 + rn3_4) == (rn7_1 + rn3_4));
    assert((rn3_4 + 7) == (rn7_1 + rn3_4));

    assert((7 - rn3_4) == (rn7_1 - rn3_4));
    assert((rn3_4 - 7) == (rn3_4 - rn7_1));

    assert((7 * rn3_4) == (rn7_1 * rn3_4));
    assert((rn3_4 * 7) == (rn7_1 * rn3_4));

    assert((7 / rn3_4) == (rn7_1 / rn3_4));
    assert((rn3_4 / 7) == (rn3_4 / rn7_1));

    // test rn und int

    double myDouble = 1.5;

    assert(RationalNumber(myDouble) == rn3_2);
    assert(myDouble == rn3_2.doubleValue());

    assert((myDouble + rn3_4) == (rn3_2 + rn3_4));
    assert((rn3_4 + myDouble) == (rn3_2 + rn3_4));

    assert((myDouble - rn3_4) == (rn3_2 - rn3_4));
    assert((rn3_4 - myDouble) == (rn3_4 - rn3_2));

    assert((myDouble * rn3_4) == (rn3_2 * rn3_4));
    assert((rn3_4 * myDouble) == (rn3_2 * rn3_4));

    assert((myDouble / rn3_4) == (rn3_2 / rn3_4));
    assert((rn3_4 / myDouble) == (rn3_4 / rn3_2));

    cout << "RN successful!\n";

    testRationalNumberArray();

    return 0;
}

void testRationalNumberArray(){

    cout << "Performing unit tests for RationalNumberArray...\n";
    RationalNumber rn3_4 ( 3, 4 );
    RationalNumber rn6_4 ( 6, 4 );
    RationalNumber rn3_2 ( 3, 2 );
    RationalNumber rnm9_m6 ( -9, -6 );
    RationalNumber rn9_m6 ( 9, -6 );
    RationalNumber rn9_4 ( 9, 4 );
    RationalNumber rn0_4 ( 0, 4 );

    RationalNumberArray rna_1(10);
    RationalNumberArray rna_2(100);
    RationalNumberArray rna_3(2);


    // test different resize versions
    rna_1.resize(20);

    assert(rna_1.capacity() == 20);

    rna_2.resize(5);

    assert(rna_2.capacity() == 5);

    assert(rna_3.capacity() == 2);
    rna_3.add(rn3_4);
    rna_3.add(rn6_4);
    rna_3.add(rn9_4);
    assert(rna_3.capacity() > 2);

    // test get
    assert(rna_3[0] == rn3_4);
    assert(rna_3[1] == rn6_4);
    assert(rna_3[2] == rn9_4);

    // test set
    rna_3.set(rn9_4, 1);
    assert(rna_3[1] == rn9_4);

    rna_3.set(rnm9_m6, 8);
    assert(rna_3.capacity() > 7 );
    assert( rna_3.size() == 9 );
    assert( rna_3[8] == rnm9_m6 );
    assert(rna_3[7] == RationalNumber());

    rna_1.resize(-1);

    assert(rna_3[8] == rnm9_m6);

    rna_3[6] = rn3_2;
    assert(rna_3[6] == rn3_2);

    RationalNumber my = rna_3[6];

    cout << "RNA successful!\n";
}

//void myTestCallbackFunction(RationalNumberArray *data){
//    printf("Error Callback");
//}
