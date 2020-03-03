#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "../code/TrigMath.h"

#include <map>

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

TEST_CASE("Test Sin") {
    TrigMath math;
    std::map<std::string, function> functions;
    functions["Sin"] = &TrigMath::Sin;
    functions["Cos"] = &TrigMath::Cos;
    std::vector<double> numbers{0.5, 1.5, 2.0};
    ApprovalTests::CombinationApprovals::verifyAllCombinations(
        [&](auto key, double d) {
            return (math.*functions[key])(d);
            },
        getKeys(functions), numbers);
}
