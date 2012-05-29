#include <iostream>
#include "pair.h"
#include "less.h"
#include "greater.h"

using namespace std;

template class Pair<int, int>;

int main(){
    Pair<string, int> p1;
    cout << p1 << "\n";


    Less<int> lessInt;
    Greater<string> greaterString;
    cout << "2<3 == " << lessInt(2,3) << endl;
    cout << "Hallo > Welt == " << greaterString("Hallo","Welt") << endl;

}
