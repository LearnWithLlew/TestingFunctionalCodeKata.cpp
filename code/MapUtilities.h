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

// TODO Fix this - remove insertion into std
namespace std
{
    template<class Key, class Value>
    std::ostream& operator<<(std::ostream& os,
                             const std::pair<Key, Value>& pair)
    {
        os << "(" << pair.first << ", " << pair.second << ")";
        return os;
    }
}


#endif //TESTINGFUNCTIONALCODEKATA_MAPUTILITIES_H
