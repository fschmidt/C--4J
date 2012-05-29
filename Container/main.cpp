#include <iostream>
#include "pair.h"
#include "less.h"
#include "greater.h"
#include "mapToFirst.h"

using namespace std;

template class Pair<int, int>;

int main(){
    Pair<string, int> p1;
    cout << p1 << endl;


    Less<int> lessInt;
    Greater<string> greaterString;
    cout << "2<3 == " << lessInt(2,3) << endl;
    cout << "Hallo > Welt == " << greaterString("Hallo","Welt") << endl;


    Pair<int,string> p7(7,"James Bond"), p42(42,"Douglas Adams");
    MapToFirst< int, string, Less<int> > lessPair;
    cout << p42 << " < " << p7<< " == " << lessPair(p42,p7) << endl;
    cout << p7 << " < " << p42<< " == " << lessPair(p7,p42) << endl;

}
