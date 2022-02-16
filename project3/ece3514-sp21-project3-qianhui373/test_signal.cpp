#include "catch.hpp"
#include "signal.hpp"

TEST_CASE("Signal Tests", "[signal]") {
    ////
  // TODO
    Signal<int> a;
    REQUIRE(a.length() == 0);//////////////////
    for (std::size_t i = 0; i < a.length(); ++i) {
        CHECK(a[i] == 4.0);
        CHECK(a.at(i) == 4.0);
    }

    
}
