/* 
 * File:   Array.cpp
 * Author: Diego Valdes
 * 
 * Created on October 28, 2015, 4:33 PM
 */

#include "Array.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

template <class T>
Array<T>::Array() : Size(0){
    Data = new T [Size];
    Data = NULL;  
}

template <class T>
Array<T>::Array(int ArraySize, T value) : Size(ArraySize) {
    Data = new T [Size];
    for(int i = 0; i < Size; i++){
        Data[i] = value;
    }
}

template <class T>
Array<T>::Array(T anArray[], int ArraySize) : Size(ArraySize){ 
    Data = new T [Size];
    for(int i = 0; i < Size; i++){
        Data[i] = anArray[i];
    }
}

template <class T>
Array<T>::Array(const Array<T> &orig) : Size(orig.Size){
	Data = new T [Size];
	for(int i = 0; i < Size; i++){
        Data[i] = orig.Data[i];
    }
}

template <class T>
Array<T>::~Array() {
  delete [] Data;
}

template <class T>
int Array<T>::size() const{
    return Size;
}

template <class T>
T Array<T>::get(int index) const{
	if(index > Size || index < 0){
		exit (0);
	}
    return Data[index];
} 

template <class T>
void Array<T>::set(int index, T value){
	if(index > Size || index < 0){
		exit (0);
	}
    Data[index] = value;
}

template <class T>
const Array<T> & Array<T>::operator =(const Array<T> &anArray){ //copy
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            this -> Data[i] = anArray.get(i);
        }
    }else{
        exit (0);
    }
	return *this;
}

template <class T>
bool Array<T>::operator ==(const Array<T> &anArray) const{ //equal 
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            if(Data[i] != anArray.get(i)){
                return false;
            }
        }return true;
    }
    return false;
}

template <class T>
const Array<T> Array<T>::operator +(const Array<T> &anArray) const{ //add 
    Array *temp;
    temp = new Array(anArray);
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            T result = Data[i] + anArray.get(i);
            temp -> Data[i] = result;
        }
    }else{
        exit (0);
    }
    return *temp;
}

template <class T>
const Array<T> & Array<T>::operator -(const Array<T> &anArray) const{ //subtract     
    Array *temp;
    temp = new Array(anArray);
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            T result = Data[i] - anArray.get(i);
            temp -> Data[i] = result;
        }
    }else{
        exit (0);
    }
    return *temp;
}

template <class T>
const Array<T> & Array<T>::operator +=(const Array<T> &anArray){
  if(Size == anArray.size()){
    for(int i = 0; i < Size; i++){
      T result = Data[i] + anArray.get(i);
      this->Data[i] = result;
    }
  }else{
    exit (0);
  }
  return *this;
}

template <class T>
const Array<T> & Array<T>::operator -=(const Array<T> &anArray){
  if(Size == anArray.size()){
    for(int i = 0; i < Size; i++){
      T result = Data[i] - anArray.get(i);
      this->Data[i] = result;
    }
  }else{
    exit (0);
  }
  return *this;
}

template <class T>
T Array<T>::operator [](int index) const{// Equivalent to get
  if(index > Size || index < 0){
    exit (0);
  }
  return Data[index];
} 

template <class T>
T & Array<T>::operator [](int index){ // Equivalent to set
  if(index > Size || index < 0){
    exit (0);
  }
  return Data[index];
} 

template <class T>
const Array<T> & Array<T>::operator++(){ //Prefix
	for(int i = 0; i < Size; i++){
		this -> Data[i] = Data[i] + 1;
	}
	return *this;
}

template <class T>
const Array<T> & Array<T>::operator++(int dummy){ //Postfix
  for(int i = 0; i < Size; i++){
    this -> Data[i] = Data[i] + 1;
  }
  return *this;
}

template <class T>
const Array<T> & Array<T>::operator-() const{
  for(int i = 0; i < Size; i++){
    this ->Data[i] = Data[i] * -1;
  }
  return *this;
}

template <class T>
void Array<T>::insert (int index, T value){
	if(index > Size || index < 0){
		exit (0);
	}
  T temp [Size];
  for(int i = 0; i < Size; i++){
    temp[i] = Data[i];
  }
  delete [] Data;
  Size++;
  Data = new T [Size];
  for(int i = 0; i < index; i++){
    Data[i] = temp[i];
  }
  Data[index] = value;
  for(int i = index+1; i < Size; i++){
    Data[i] = temp[i-1];
  }
}

template <class T>
T Array<T>::remove (int index){
	if(index > Size || index < 0){
		exit (0);
	}
  T deleted = Data[index];
  T temp [Size];
  for(int i = 0; i < Size; i++){
    temp[i] = Data[i];
  }
  delete [] Data;
  Size--;
  Data = new T [Size];
  for(int i = 0; i < index; i++){
    Data[i] = temp[i];
  }
  for(int i = index; i < Size; i++){
    Data[i] = temp[i+1];
  }
  return deleted;
}

template <class T>
ostream & operator<< (ostream & outStream, const Array<T> &anArray){ 
	for(int i = 0; i < anArray.size(); i++){
        cout << " " << anArray.get(i) << " " ;
    }
	cout << endl;
  return outStream;
}

template <class T>
istream & operator>> (istream & inStream, Array<T> &anArray){
	for(int i = 0; i < anArray.size(); i++){
		int value;
	  cout << "enter a value " << endl;
        cin >> value;
		anArray.set(i, value);
    }
	return inStream;
} 

template <class T>
void Array<T>::Print() const{
    for(int i = 0; i < Size; i++){
        cout << " " << Data[i] << " " ;
    }
    cout << endl;
}
