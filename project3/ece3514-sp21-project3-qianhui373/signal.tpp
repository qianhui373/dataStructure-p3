#include "signal.hpp"

// TODO
#include "math.h"
#include <utility>
#include <algorithm>
#include <stdexcept>

// construct a default signal of given length
template<typename T>
Signal<T>::Signal(std::size_t length, T value){
    m_size = length;
    m_capacity = 2*length;
    m_array = new T[m_size];
    for(std::size_t i = 0; i < m_size; ++i){
        m_array[i] = value;
    }
}


////////////////////////////////////////////////////////////////////////////////////////
//destroy constructor
template<typename T>
Signal <T>::~Signal(){
	delete [] m_array;
}


//copy 
template<typename T>////////////////////////////////////////////////////////////////////////////
Signal<T>::Signal(const Signal<T> & rhs){
	

    m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;
    m_array = new T[m_capacity];
    for(std::size_t i = 0; i < m_size; ++i){
        m_array[i] = rhs.m_array[i];
    }

for(std::size_t i = m_size; i < m_capacity; ++i){
        m_array[i] = T();
    }
}
////

// do an assignment to signal (deep copy)
template<typename T>////////////////////////////////////////////////////////////////////////////////
Signal<T> & Signal<T>::operator=(const Signal<T> & rhs){


m_capacity = rhs.m_capacity;
    m_size = rhs.m_size;
    m_array = new T[m_capacity];
    for(std::size_t i = 0; i < m_size; ++i){
        m_array[i] = rhs.m_array[i];
    }

for(std::size_t i = m_size; i < m_capacity; ++i){
        m_array[i] = T();
    }

   
    return *this;
    
}


//// move constructor for signal
template<typename T>
Signal<T>::Signal(Signal<T>&& x){
    //steal the contents of x
    std::swap(m_capacity, x.m_capacity);
    std::swap(m_size, x.m_size);
    std::swap(m_array, x.m_array);

}


//
// move assignment for signal
template<typename T>
Signal<T>& Signal<T>::operator=(Signal<T> && x){
    
  //but current object back to default
  delete [] m_array ;
  m_capacity = 0;
  m_size = 0;
  m_array = nullptr;
  // copy-swap idiom
  std::swap(m_size, x.m_size);
  std::swap(m_capacity, x.m_capacity);
  std::swap(m_array, x.m_array);

  return *this;
}


// get the number of samples in ths signal
template<typename T>
std::size_t Signal<T>::length() const noexcept{
  //TODO
  return m_size;
}




//// get copy of the sample at index
  // throws std::invalid_argument if invalid
template<typename T>
T Signal<T>::at(std::size_t index) const{

  if(index >= m_size){
    throw std::invalid_argument("invalid index in call to at");
  }
  
  return m_array[index];
}





//// get reference to the sample at index
  // throws std::invalid_argument if invalid
template<typename T>
T& Signal<T>::at(std::size_t index){

  if(index >= m_size){
    throw std::invalid_argument("invalid index in call to at");
  }

  return m_array[index];
}



//
// get copy of the sample at index
template<typename T>
T Signal<T>::operator[](std::size_t index) const noexcept{

  return m_array[index];
}


//// get reference to the sample at index
template<typename T>
T& Signal<T>::operator[](std::size_t index) noexcept{

  return m_array[index];
}


//pad
template <typename T>
bool Signal<T>::pad(std::size_t newlength, T value){
  

  if(newlength < m_size){
    return false;
  }
else {

  //newlength--;
  //need to allocate


    //for (newlength = (m_capacity == 0) ? 1 : 2*m_capacity;
    T* temp = new T[newlength];
    for(std::size_t i = 0; i < m_size; ++i){
        temp[i] = m_array[i];
    }
    for (std::size_t i = m_size; i < newlength; ++i) {
        temp[i] = value;

    }
    delete[] m_array;
    m_array =temp;


 
  //scoot over
  
m_size = newlength;
  //m_array[newlength] = value;
  //m_size++;


  return true;
}
}


