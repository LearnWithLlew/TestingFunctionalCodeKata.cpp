#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "../code/TrigMath.h"
#include "../code/MapUtilities.h"

#include <map>

using namespace ApprovalTests;

TEST_CASE("Test Sin")
{
    TrigMath math;
    std::map<std::string, decltype(&TrigMath::Sin)> functions;
    functions["Sin"] = &TrigMath::Sin;
    functions["Cos"] = &TrigMath::Cos;
    std::vector<double> numbers{0.5, 1.5, 2.0};
    ApprovalTests::CombinationApprovals::verifyAllCombinations(
        [&](auto key, double d) { return (math.*functions[key])(d); },
        getKeys(functions),
        numbers);
}
