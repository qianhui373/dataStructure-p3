#ifndef SIGNAL_HPP
#define SIGNAL_HPP

#include <cstddef>

/* class Signal

Class representing a discrete-time signal of arbitrary length, each sample
of a numeric type T. T must at least support default construct and copy.
Indexing into the signal is 0-based.
*/
template <typename T>
class Signal
{
public:

  // construct a default signal of length zero
  Signal() = default;

  // construct a default signal of given length
  // initialized to the constant value, defaults to
  // default of T
  Signal(std::size_t length, T value = T());

  // destroy a signal
  ~Signal();

  // copy construct a signal
  Signal(const Signal<T> & rhs);
  ////
  // do an assignment to signal (deep copy)
  Signal<T> & operator=(const Signal<T> &rhs);

  // move constructor for signal
  Signal(Signal<T>&& x);

  // move assignment for signal
  Signal<T>& operator=(Signal<T>&& x);

  // get the number of samples in ths signal
  std::size_t length() const noexcept;
  
  // get copy of the sample at index
  // throws std::invalid_argument if invalid
  T at(std::size_t index) const;

  // get reference to the sample at index
  // throws std::invalid_argument if invalid
  T & at(std::size_t index);

  // get copy of the sample at index
  T operator[](std::size_t index) const noexcept;

  // get reference to the sample at index
  T & operator[](std::size_t index) noexcept;

  // extend signal to new length, inserting constants value
  // returns false if newlength (strictly) less than current length, else returns true
  bool pad(std::size_t newlength, T value = T());
  
private:

  // TODO
    //constexpr static std::size_t length = 100;

    //int data[length];

    std::size_t m_size = 0;
    std::size_t m_capacity = 0;
    T* m_array = nullptr;
};

#include "signal.tpp"

#endif
