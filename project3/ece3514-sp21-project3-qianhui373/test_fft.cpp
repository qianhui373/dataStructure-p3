#include "catch.hpp"
#include <cmath>
#include "complex.hpp"
#include "signal.hpp"
#include "fft.hpp"
////
#include <stdexcept>
constexpr double eps = 1e-14;


TEST_CASE("FFT Tests", "[fft]") {
  // TODO

  Signal<Complex> input(4);
  input[0] = Complex(1,0);
  input[1] = Complex(2,0);
  input[2] = Complex(3,0);
  input[3] = Complex(4,0);
  
  fft(input);
  
  Signal<Complex> output = fft(input);
  
  REQUIRE(output.length() == 4);
  
  REQUIRE(output[0].real() == Approx(10.0).margin(eps));
  REQUIRE(output[0].imag() == Approx(0.0).margin(eps));
  
  REQUIRE(output[1].real() == Approx(-2.0).margin(eps));
  REQUIRE(output[1].imag() == Approx(2.0).margin(eps));
  
  REQUIRE(output[2].real() == Approx(-2.0).margin(eps));
  REQUIRE(output[2].imag() == Approx(0.0).margin(eps));
    
  REQUIRE(output[3].real() == Approx(-2.0).margin(eps));
  REQUIRE(output[3].imag() == Approx(-2.0).margin(eps));
}

//TEST_CASE("FFT Test 2", "[fft]") {
//
//    typedef Signal<Complex> SignalType;
//
//    SignalType in;
//
//    in[0] = Complex(1, 0);
//
//    SignalType fftout = fft(in);
//
//    for (std::size_t i = 0; i < 8; ++i) {
//        REQUIRE(fftout[0].real() == Approx(1.0).margin(eps));
//        REQUIRE(fftout[0].imag() == Approx(0.0).margin(eps));
//    }
//}
//
//TEST_CASE("FFT Test 3", "[fft]") {
//
//    typedef Signal<Complex> SignalType;
//
//    SignalType in;
//
//    in[1] = Complex(1, 0);
//
//    SignalType fftout = fft(in);
//
//    double halfsqrt2 = sqrt(2) / 2;
//
//    REQUIRE(fftout[0].real() == Approx(1.0).margin(eps));
//    REQUIRE(fftout[0].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[1].real() == Approx(halfsqrt2).margin(eps));
//    REQUIRE(fftout[1].imag() == Approx(-halfsqrt2).margin(eps));
//
//    REQUIRE(fftout[2].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[2].imag() == Approx(-1.0).margin(eps));
//
//    REQUIRE(fftout[3].real() == Approx(-halfsqrt2).margin(eps));
//    REQUIRE(fftout[3].imag() == Approx(-halfsqrt2).margin(eps));
//
//    REQUIRE(fftout[4].real() == Approx(-1.0).margin(eps));
//    REQUIRE(fftout[4].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[5].real() == Approx(-halfsqrt2).margin(eps));
//    REQUIRE(fftout[5].imag() == Approx(halfsqrt2).margin(eps));
//
//    REQUIRE(fftout[6].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[6].imag() == Approx(1.0).margin(eps));
//
//    REQUIRE(fftout[7].real() == Approx(halfsqrt2).margin(eps));
//    REQUIRE(fftout[7].imag() == Approx(halfsqrt2).margin(eps));
//
//}
//
//TEST_CASE("FFT Test 4", "[fft]") {
//
//    typedef Signal<Complex> SignalType;
//
//    SignalType in;
//
//    in[0] = Complex(1, 0);
//    in[1] = Complex(-1, 0);
//    in[2] = Complex(1, 0);
//    in[3] = Complex(-1, 0);
//    in[4] = Complex(1, 0);
//    in[5] = Complex(-1, 0);
//    in[6] = Complex(1, 0);
//    in[7] = Complex(-1, 0);
//
//    SignalType fftout = fft(in);
//
//    REQUIRE(fftout[0].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[0].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[1].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[1].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[2].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[2].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[3].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[3].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[4].real() == Approx(8.0).margin(eps));
//    REQUIRE(fftout[4].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[5].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[5].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[6].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[6].imag() == Approx(0.0).margin(eps));
//
//    REQUIRE(fftout[7].real() == Approx(0.0).margin(eps));
//    REQUIRE(fftout[7].imag() == Approx(0.0).margin(eps));
//
//}
//
//TEST_CASE("Test fft when length not a power of 2", "[fft]") {
//
//    Signal<Complex> s;
//
//    REQUIRE_THROWS_AS(fft(s), std::invalid_argument);
//}
//
