#ifndef TESTINGFUNCTIONALCODEKATA_MAPUTILITIES_H
#define TESTINGFUNCTIONALCODEKATA_MAPUTILITIES_H

#include <map>
#include <string>

template<class Key, class Value>
std::vector<Key> getKeys(const std::map<Key, Value>& map)
{
    std::vector<Key> keys;
    for( const auto& pair : map)
    {
        keys.push_back(pair.first);
    }
    return keys;
}

#endif //TESTINGFUNCTIONALCODEKATA_MAPUTILITIES_H
