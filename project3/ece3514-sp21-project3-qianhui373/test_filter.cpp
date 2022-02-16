#include "catch.hpp"

#include <cmath>

#include "complex.hpp"
#include "signal.hpp"
#include "filter.hpp"

constexpr double eps = 1e-14;

TEST_CASE("Test filter API", "[filter]") {
////
  {
    Signal<Complex> input(256);
    Filter f;
    
    f.setInput(input);
    REQUIRE(input.length() == 256);
  }

  {
    Signal<Complex> input(256);
    Filter f;
    
    f.setInput(std::move(input));

    REQUIRE(input.length() == 0);
  }

  {
    Signal<Complex> input(256);
    Signal<Complex> h(256);
    Filter f;

    f.setInput(std::move(input));
    f.setImpulseResponse(std::move(h));

    f.apply();

    Signal<Complex> output = f.getOutput();

    REQUIRE(output.length() == 256);
  }

  {
    Signal<Complex> input(100);
    Signal<Complex> h(129);
    Filter f;

    f.setInput(std::move(input));
    f.setImpulseResponse(std::move(h));

    f.apply();

    Signal<Complex> output = f.getOutput();

    REQUIRE(output.length() == 256);
  }

  {
    Signal<Complex> input(129);
    Signal<Complex> h(10);
    Filter f;

    f.setInput(std::move(input));
    f.setImpulseResponse(std::move(h));

    f.apply();

    Signal<Complex> output = f.getOutput();

    REQUIRE(output.length() == 256);
  }
}

TEST_CASE("Filter Test 1", "[filter]") {

  Signal<Complex> in(4);
  in[0] = Complex(1,0);
  in[1] = Complex(2,0);
  in[2] = Complex(3,0);
  in[3] = Complex(4,0);
  
  Signal<Complex> h(100);
  h[0] = 1.0;

  Filter f;
  f.setInput(std::move(in));
  f.setImpulseResponse(std::move(h));

  f.apply();
  
  Signal<Complex> out = f.getOutput();
  
  REQUIRE(out.length() == 128);
  
  REQUIRE(out[0].real() == Approx(1.0).margin(eps));
  REQUIRE(out[0].imag() == Approx(0.0).margin(eps));
  
  REQUIRE(out[1].real() == Approx(2.0).margin(eps));
  REQUIRE(out[1].imag() == Approx(0.0).margin(eps));
  
  REQUIRE(out[2].real() == Approx(3.0).margin(eps));
  REQUIRE(out[2].imag() == Approx(0.0).margin(eps));
    
  REQUIRE(out[3].real() == Approx(4.0).margin(eps));
  REQUIRE(out[3].imag() == Approx(0.0).margin(eps)); 
}

TEST_CASE("Filter Test 2", "[filter]") {

  Signal<Complex> in(1000);
  Signal<Complex> h(1000);
  for(std::size_t i = 0; i < 1000; ++i){
    in[i] = Complex(pow(0.5, i),0);
    h[i] = Complex(pow(0.25, i),0);
  }

  Filter f;
  f.setInput(std::move(in));
  f.setImpulseResponse(std::move(h));

  f.apply();

  Signal<Complex> out = f.getOutput();

  REQUIRE(out.length() == 1024);
  for(std::size_t i = 0; i < 1024; ++i){
    double y = 4*(pow(0.5, i+1) - pow(0.25, i+1));
    REQUIRE(out[i].real() == Approx(y).margin(eps));
    REQUIRE(out[i].imag() == Approx(0.0).margin(eps));
  }
}

TEST_CASE("Filter Test 3", "[filter]") {

  Signal<Complex> in(1000);
  Signal<Complex> h(1000);
  for(std::size_t i = 0; i < 1000; ++i){
    in[i] = Complex(pow(0.1, i),pow(0.2, i));
    h[i] = Complex(pow(0.1, i),pow(0.2, i));
  }

  Filter f;
  f.setInput(std::move(in));
  f.setImpulseResponse(std::move(h));

  f.apply();

  Signal<Complex> out = f.getOutput();

  REQUIRE(out.length() == 1024);
  for(std::size_t i = 0; i < 1024; ++i){
    double re = (i+1)*(pow(0.1, i) - pow(0.2, i));
    double im = 20*(pow(0.2, i+1) - pow(0.1, i+1));
    REQUIRE(out[i].real() == Approx(re).margin(eps));
    REQUIRE(out[i].imag() == Approx(im).margin(eps));
  }
}
