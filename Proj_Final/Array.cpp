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

Array::Array() : Size(0){
    Data = new int [Size];
    Data = NULL;  
}

Array::Array(int ArraySize, int value) : Size(ArraySize) {
    Data = new int [Size];
    for(int i = 0; i < Size; i++){
        Data[i] = value;
    }
}

Array::Array(int anArray[], int ArraySize) : Size(ArraySize){ 
    Data = new int [Size];
    for(int i = 0; i < Size; i++){
        Data[i] = anArray[i];
    }
}

Array::Array(const Array &orig) : Size(orig.Size){
	Data = new int [Size];
	for(int i = 0; i < Size; i++){
        Data[i] = orig.Data[i];
    }
}

Array::~Array() {
  delete [] Data;
}

int Array::size() const{
    return Size;
}

int Array::get(int index) const{
	if(index > Size || index < 0){
		exit (0);
	}
    return Data[index];
}

void Array::set(int index, int value){
	if(index > Size || index < 0){
		exit (0);
	}
    Data[index] = value;
}

const Array & Array::operator =(const Array &anArray){ //copy
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            this -> Data[i] = anArray.get(i);
        }
    }else{
        exit (0);
    }
	return *this;
}

bool Array::operator ==(const Array &anArray) const{ //equal 
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            if(Data[i] != anArray.get(i)){
                return false;
            }
        }return true;
    }
    return false;
}

const Array Array::operator +(const Array &anArray) const{ //add 
    Array *temp;
    temp = new Array(anArray);
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            int result = Data[i] + anArray.get(i);
            temp -> Data[i] = result;
        }
    }else{
        exit (0);
    }
    return *temp;
}

const Array & Array::operator -(const Array &anArray) const{ //subtract     
    Array *temp;
    temp = new Array(anArray);
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            int result = Data[i] - anArray.get(i);
            temp -> Data[i] = result;
        }
    }else{
        exit (0);
    }
    return *temp;
}

const Array & Array::operator +=(const Array &anArray){
  if(Size == anArray.size()){
    for(int i = 0; i < Size; i++){
      int result = Data[i] + anArray.get(i);
      this->Data[i] = result;
    }
  }else{
    exit (0);
  }
  return *this;
}

const Array & Array::operator -=(const Array &anArray){
  if(Size == anArray.size()){
    for(int i = 0; i < Size; i++){
      int result = Data[i] - anArray.get(i);
      this->Data[i] = result;
    }
  }else{
    exit (0);
  }
  return *this;
}

int Array::operator [](int index) const{// Equivalent to get
  if(index > Size || index < 0){
    exit (0);
  }
  return Data[index];
} 

int & Array::operator [](int index){ // Equivalent to set
  if(index > Size || index < 0){
    exit (0);
  }
  return Data[index];
} 

const Array & Array::operator++(){ //Prefix
	for(int i = 0; i < Size; i++){
		this -> Data[i] = Data[i] + 1;
	}
	return *this;
}

const Array & Array::operator++(int dummy){ //Postfix
  for(int i = 0; i < Size; i++){
    this -> Data[i] = Data[i] + 1;
  }
  return *this;
}

const Array & Array::operator-() const{
  for(int i = 0; i < Size; i++){
    this ->Data[i] = Data[i] * -1;
  }
  return *this;
}

void Array::insert (int index, int value){
	if(index > Size || index < 0){
		exit (0);
	}
  int temp [Size];
  for(int i = 0; i < Size; i++){
    temp[i] = Data[i];
  }
  delete [] Data;
  Size++;
  Data = new int [Size];
  for(int i = 0; i < index; i++){
    Data[i] = temp[i];
  }
  Data[index] = value;
  for(int i = index+1; i < Size; i++){
    Data[i] = temp[i-1];
  }
}

int Array::remove (int index){
	if(index > Size || index < 0){
		exit (0);
	}
  int deleted = Data[index];
  if(index > Size){
    exit(0);
  }
  int temp [Size];
  for(int i = 0; i < Size; i++){
    temp[i] = Data[i];
  }
  delete [] Data;
  Size--;
  Data = new int [Size];
  for(int i = 0; i < index; i++){
    Data[i] = temp[i];
  }
  for(int i = index; i < Size; i++){
    Data[i] = temp[i+1];
  }
  return deleted;
}

ostream & operator<<(ostream & outStream, const Array &anArray){ 
	for(int i = 0; i < anArray.size(); i++){
        cout << " " << anArray.get(i) << " " ;
    }
	cout << endl;
  return outStream;
}

istream & operator>>(istream & inStream, Array &anArray){
	for(int i = 0; i < anArray.size(); i++){
		int value;
	  cout << "enter a value " << endl;
        cin >> value;
		anArray.set(i, value);
    }
	return inStream;
} 

void Array::Print() const{
    for(int i = 0; i < Size; i++){
        cout << " " << Data[i] << " " ;
    }
    cout << endl;
}
