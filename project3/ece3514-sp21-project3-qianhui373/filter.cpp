#include "filter.hpp"
#include "math.h"
#include <cstddef>
#include <cmath>
#include "complex.hpp"
#include <stdexcept>
void Filter::setInput(const Signal<Complex> & input){
  x = input;
}
  
void Filter::setInput(Signal<Complex> && input){
  x = std::move(input);
}

void Filter::setImpulseResponse(const Signal<Complex> & input){
  h = input;
}

void Filter::setImpulseResponse(Signal<Complex> && input){
  h = std::move(input);
}

void Filter::apply(){
  // TODO
    
    std::size_t n = x.length();
    std::size_t m = h.length();
    //std::size_t L = 2;
    
    //Signal<Complex> y(L);
    
    /*if (m > n) {
        if (m % 2 == 0) {
            L = m;
        }
        else if (m % 2 != 0) {
            L = m + 1;
        }
    }
    else if (n > m) {
        if (n % 2 == 0) {
            L = n;
        }
        else if (n % 2 != 0) {
            L = n + 1;
        }
    }*/

    	std::size_t L = 1;
    while (L < std::max(m, n))
    	L *= 2;


    Signal<Complex>Y(L);
    
    x.pad(L);
    h.pad(L);

    Signal<Complex> X = fft(x);
    Signal<Complex> H = fft(h);
    
    
    
    for (std::size_t i = 0; i < L; ++i) {
        Y[i] = mul(X[i], H[i]);
    }
    
    

    Signal<Complex> outsignal = Y;
    Signal<Complex>y(L);
        for (std::size_t i = 0; i < L; ++i) {

            Complex n = neg(Y[i]);
            Y[i] = Complex(Y[i].real(), n.imag());

        }

        outsignal = fft(outsignal);
        for (std::size_t s = 0; s < L; ++s) {

            Complex n = neg(outsignal[s]);
            outsignal[s] = Complex(outsignal[s].real(), n.imag());
            y[s] = Complex(outsignal[s].real() / L, outsignal[s].imag() / L);


        }

        output = y;
    }
    
    
  

Signal<Complex> Filter::getOutput(){
  return std::move(output);
}


