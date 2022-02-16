#include "catch.hpp"

#include "complex.hpp"

// TODO
////

// Note this test will fail to compile if you do not have the
// correct member function declarations.
TEST_CASE("Test const correctness of Complex", "[complex]") {

    Complex z1(-1, -1);
    Complex z2(-2, -2);
    Complex z(1, 3);

    REQUIRE(z1.real() == -1);
    REQUIRE(z1.imag() == -1);

    REQUIRE(z2.real() == -2);
    REQUIRE(z2.imag() == -2);

    REQUIRE(z.real() == 1);
    REQUIRE(z.imag() == 3);
}


