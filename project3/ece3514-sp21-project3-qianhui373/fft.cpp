#include "fft.hpp"

// TODO
#include <cstddef>
#include <cmath>
#include "complex.hpp"
#include <stdexcept>
#include "math.h"

#define PI 3.14159265358979323846


////

Signal<Complex> fft(const Signal<Complex>& in) {


	std::size_t n = in.length();
	Signal<Complex> output(n);

	for (std::size_t i = 0; i <= n - 1; ++i) {

			output[i] = in[bitreverse(i, log2(n))];
	}

	for (std::size_t s = 1; s <= log2(n); ++s) {

		Complex w(1, 0);

		for (std::size_t j = 0; j <= pow(2, (s - 1)) - 1; ++j) {
			for (std::size_t k = j; k <= n - 1; k = k + pow(2, s)) {

				Complex funOut = output.at(k + pow(2, s - 1));
				Complex t = mul(w, funOut);
				Complex u = output[k];
				output[k] = add(t, u);
				output[k + pow(2, s - 1)] = add(u, neg(t));
			}


			Complex w1(cos(-2 * PI / pow(2, s)), sin(-2 * PI / pow(2, s)));
			w = mul(w, w1);
		}
	}

	return output;

}



std::size_t bitreverse(std::size_t x, int log2n) {

	std::size_t n = 0;
	for (std::size_t i = 0; i < log2n; i++) {

		n <<= 1;
		n |= (x & 1);
		x >>= 1;
	}
	return n;
}