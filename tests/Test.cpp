#include "Catch.hpp"
#include "../code/TrigMath.h"

using namespace std;



TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.0) == math.Sin(3.4));
}
