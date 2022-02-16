#ifndef FFT_HPP
#define FFT_HPP

#include "complex.hpp"
#include "signal.hpp"
#include <cstddef>
/////
Signal<Complex> fft(const Signal<Complex> & in);

std::size_t bitreverse(std::size_t x, int log2n);


#endif
