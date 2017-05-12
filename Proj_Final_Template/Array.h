/* 
 * File:   Array.h
 * Author: homayoun
 *
 * Created on October 21, 2015, 11:51 AM
 */

#ifndef ARRAY_H
#define	ARRAY_H
#include <iostream>
using namespace std;
template <class T>


class Array {
  
  
public:
  Array(); //complete
  Array(int arraySize, T value = 0); //complete
  Array(T anArray[], int arraySize); //complete
  Array(const Array<T> &orig); //complete
  virtual ~Array(); //complete
  
  const Array<T> & operator=(const Array<T> & rhs); //complete
  const Array<T> operator+(const Array<T> & rhs) const; //complete
  const Array<T> & operator-(const Array<T> & rhs) const; //complete
  const Array<T> & operator+=(const Array<T> & rhs); //complete
  const Array<T> & operator-=(const Array<T> & rhs); //complete
  
  const Array<T> & operator++(); //complete
  const Array<T> & operator++(int dummy); //complete
  const Array<T> & operator-() const; //complete
  
  bool operator==(const Array & rhs) const; //complete
  T operator[](int index) const; // Equivalent to get - complete
  T & operator[](int index); // Equivalent to set - complete
  
  void Print(void) const; //complete
  void set(int index, T value); //complete
  T get(int index) const; //complete
  int size() const; //complete
  void insert(int index, T value); //complete
  T remove(int index); //complete
  
  template <class U>
  friend ostream & operator<< (ostream & outStream, const Array<U> & rhs);
  template <class U>
  friend istream & operator>> (istream & inStream, Array<U> & rhs);
  
private:
  int Size;
  T *Data;
};

#endif	/* ARRAY_H */
