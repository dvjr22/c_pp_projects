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

class Array {
public:
  Array(); //complete
  Array(int arraySize, int value = 0); //complete
  Array(int anArray[], int arraySize); //complete
  Array(const Array &orig); //complete
  virtual ~Array(); //complete
  
  const Array & operator=(const Array & rhs); //complete
  const Array operator+(const Array & rhs) const; //complete
  const Array & operator-(const Array & rhs) const; //complete
  const Array & operator+=(const Array & rhs); //complete
  const Array & operator-=(const Array & rhs); //complete
  
  const Array & operator++(); //complete
  const Array & operator++(int dummy); //complete
  const Array & operator-() const; //complete
  
  bool operator==(const Array & rhs) const; //complete
  int operator[](int index) const; // Equivalent to get - complete
  int & operator[](int index); // Equivalent to set - complete
  
  void Print(void) const; //complete
  void set(int index, int value); //complete
  int get(int index) const; //complete
  int size() const; //complete
  void insert(int index, int value); //complete
  int remove(int index); //complete
  
  friend ostream & operator<<(ostream & outStream, const Array & rhs); //complete
  friend istream & operator>>(istream & inStream, Array & rhs); //complete
  
  
private:
  int Size;
  int *Data;
};

#endif	/* ARRAY_H */
