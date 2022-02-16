	#ifndef COMPLEX_HPP
#define COMPLEX_HPP

// TODO

/////
#include <cstddef>
#include <complex>
////
// TODO
class Complex {
public:
	//default construct
	//Complex();

	//construct imaginary
	Complex(double re = 0.0, double im = 0.0);


	double real() const;

	double imag() const;



private:
	double r;
	double i;

};

Complex mul(Complex z1, Complex z2);

Complex add(Complex z1, Complex z2);

Complex neg(Complex z);


#endif
