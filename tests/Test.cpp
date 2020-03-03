#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "../code/TrigMath.h"
#include "../code/MapUtilities.h"

#include <map>

using namespace ApprovalTests;

TEST_CASE("Test Sin")
{
    std::vector<double> numbers{0.5, 1.5, 2.0};
    std::map<std::string, decltype(&TrigMath::Sin)> functions;
    functions["Sin"] = &TrigMath::Sin;
    functions["Cos"] = &TrigMath::Cos;
    ApprovalTests::CombinationApprovals::verifyAllCombinations(
        [&](auto pair, double d) { return (TrigMath().*pair.second)(d); },
        functions,
        numbers);
}
