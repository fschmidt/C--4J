#include "config_reader.h"
#include <iostream>
#include <map>

// from http://www.cplusplus.com/forum/general/21115/
//---------------------------------------------------------------------------
// The extraction operator reads configuration::data until EOF.
// Invalid data is ignored.
//
std::istream& operator >> ( std::istream& ins, std::map<std::string, std::string> &d ) {
    std::string s, key, value;

    // For each (key, value) pair in the file
    while (std::getline( ins, s ))
    {
        std::string::size_type begin = s.find_first_not_of( " \f\t\v" );

        // Skip blank lines
        if (begin == std::string::npos) continue;

        // Skip commentary
        if (std::string( "#;" ).find( s[ begin ] ) != std::string::npos) continue;

        // Extract the key value
        std::string::size_type end = s.find( '=', begin );
        key = s.substr( begin, end - begin );

        // (No leading or trailing whitespace allowed)
        key.erase( key.find_last_not_of( " \f\t\v" ) + 1 );

        // No blank keys allowed
        if (key.empty()) continue;

        // Extract the value (no leading or trailing whitespace allowed)
        begin = s.find_first_not_of( " \f\n\r\t\v", end + 1 );
        end   = s.find_last_not_of(  " \f\n\r\t\v" ) + 1;

        value = s.substr( begin, end - begin );

        // Insert the properly extracted (key, value) pair into the map
        d[ key ] = value;
    }

    return ins;
}
