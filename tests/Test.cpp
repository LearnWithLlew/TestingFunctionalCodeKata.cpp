#include "../code/MapUtilities.h"
#include <catch2/catch.hpp>
#include "ApprovalTests.hpp"
#include "../code/TrigMath.h"

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

TEST_CASE("Starter Test")
{
    std::vector<double> numbers{0.0};
    std::map<std::string, decltype(&TrigMath::Sin)> functions;
    functions["Sin"] = &TrigMath::Sin;
    ApprovalTests::CombinationApprovals::verifyAllCombinations(
        [](auto pair, double d) { return (TrigMath().*pair.second)(d); },
        functions,
        numbers);
}

TEST_CASE("Starter Test 2")
{
    std::vector<double> numbers{0.0};
    std::map<std::string, decltype(&TrigMath::Sin)> functions;
    functions["Sin"] = &TrigMath::Sin;
    ApprovalTests::CombinationApprovals::verifyAllCombinations(
        [&](auto key, double d) { return (TrigMath().*functions[key])(d); },
        getKeys(functions),
        numbers);
}

double calculateValue(std::pair<std::string, decltype(&TrigMath::Sin)> pair, double d)
{
    return (TrigMath().*pair.second)(d);
}

TEST_CASE("Starter Test 3")
{
    std::vector<double> numbers{0.0};
    std::map<std::string, decltype(&TrigMath::Sin)> functions;
    functions["Sin"] = &TrigMath::Sin;
    ApprovalTests::CombinationApprovals::verifyAllCombinations(
        calculateValue,
        functions,
        numbers);
}

TEST_CASE("Starter Test 4")
{
    std::vector<double> numbers{0.0};
    std::map<std::string, std::function<double(double)>> functions;
    functions["Sin"] = [](auto d){return TrigMath().Sin(d);};
    ApprovalTests::CombinationApprovals::verifyAllCombinations(
        [&](auto key, double d) { return (functions[key])(d); },
        getKeys(functions),
        numbers);
}
