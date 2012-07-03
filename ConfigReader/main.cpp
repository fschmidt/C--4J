#include <iostream>
#include <fstream>
#include <config_reader.h>
#include <map>

using namespace std;

int main()
{
    map<string, string> config;
    ifstream f( "C:/Users/Frank/Desktop/haushaltsbuch.ini");
    f >> config;

    f.close();
    string s ("host");
    cout << config[s];
    return 0;
}

