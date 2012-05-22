#include <iostream>
#include "pair.h"

using namespace std;

template class Pair<int, int>;

int main(){
    Pair<string, int> p1;
    cout << p1;


}
