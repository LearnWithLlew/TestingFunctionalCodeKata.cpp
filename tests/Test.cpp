#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "../code/TrigMath.h"

#include <iostream>
#include <map>

//using namespace std;
using namespace ApprovalTests;
typedef double (TrigMath::*function)(double);


std::vector<std::string> getKeys(const std::map<std::string, function>& map)
{
    std::vector<std::string> keys;
    for( const auto& pair : map)
    {
        keys.push_back(pair.first);
    }
    return keys;
}

#include <map>
#include <ostream>

namespace std
{
    inline std::ostream& operator<<(std::ostream& os,
                                    const std::pair<std::string, int>& pair)
    {
        os << "(" << pair.first << ", " << pair.second << ")";
        return os;
    }
}

//typedef std::map<std::string, &TrigMath::Sin> functions;


TEST_CASE("Test Sin") {
    TrigMath math;
//    auto m = &TrigMath::Sin;
    std::map<std::string, function> functions;
    functions["Sin"] = &TrigMath::Sin;
    functions["Cos"] = &TrigMath::Cos;
//    std::cout << (math.*m)(2.0) << '\n';
//    REQUIRE(Approx(0.0) == math.Sin(3.4));
//    functions.begin()->second;
//    std::vector<double> numbers{0.5, 1.5, 2.0};
    const std::vector<std::string>& keys = getKeys(functions);
//    ApprovalTests::CombinationApprovals::verifyAllCombinations(
//        [&](auto key, double d) {
////            std::stringstream s;
////            s << (m.*functions[key.first])(d);
////            return (math.*functions[key])(d);
//    return "3.0";
////            s << key.first;
////            return s.str();
//            },
//        numbers, numbers);

    std::vector<std::string> v{"hello", "world"};
    std::vector<int> numbers{1, 2, 3};
    CombinationApprovals::verifyAllCombinations(
        [](std::string s, int i) { return "Hello"; }, v, numbers);
}
