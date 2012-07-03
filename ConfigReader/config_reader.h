#ifndef CONFIGREADER_H
#define CONFIGREADER_H

#include <iostream>
#include <map>

std::istream& operator >> ( std::istream& ins, std::map<std::string, std::string> &d );

#endif // CONFIGREADER_H


