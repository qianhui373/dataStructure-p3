#ifndef FILTER_HPP
#define FILTER_HPP

#include "complex.hpp"
#include "signal.hpp"
#include "fft.hpp"

class Filter
{
public:
  // default constructor
  Filter() = default;

  // prevent copies
  Filter(const Filter& x) = delete;

  // prevent assignment
  Filter& operator=(Filter&) = delete ;

  // copy input signal into filter
  void setInput(const Signal<Complex> & input);

  // move input signal into filter
  void setInput(Signal<Complex> && input);

  // copy impulse response into filter
  void setImpulseResponse(const Signal<Complex> & input);

  // move impulse response  into filter
  void setImpulseResponse(Signal<Complex> && input);

  // compute the filter output
  void apply();

  // move result out of filter
  Signal<Complex> getOutput();

private:

  Signal<Complex> x;
  Signal<Complex> h;
  Signal<Complex> output;
};


#endif
