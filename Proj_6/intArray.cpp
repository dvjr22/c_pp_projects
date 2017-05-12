/* 
 * File:   intArray.cpp
 * Author: Diego Valdes
 * 
 * Created on October 28, 2015, 4:33 PM
 */

#include "intArray.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

intArray::intArray() : Size(0){
    Data = new int [Size];
    Data = NULL;  
}

intArray::intArray(int ArraySize, int value = 0) : Size(ArraySize) {
    Data = new int [Size];
    for(int i = 0; i < Size; i++){
        Data[i] = value;
    }
}

intArray::intArray(int anArray[], int ArraySize) : Size(ArraySize){ 
    Data = new int [Size];
    for(int i = 0; i < Size; i++){
        Data[i] = anArray[i];
    }
}

intArray::intArray(intArray &orig) : Size(orig.Size){
	Data = new int [Size];
	for(int i = 0; i < Size; i++){
        Data[i] = orig.Data[i];
    }
}

intArray::~intArray() {
  delete [] Data;
}

int intArray::size(){
    return Size;
}

int intArray::get(int index){
	if(index > Size || index < 0){
		exit (0);
	}
    return Data[index];
}

void intArray::set(int index, int value){
	if(index > Size || index < 0){
		exit (0);
	}
    Data[index] = value;
}

intArray & intArray::operator =(intArray &anArray){ //copy
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            this -> Data[i] = anArray.get(i);
        }
    }else{
        exit (0);
    }
	return *this;
}

bool intArray::operator ==(intArray &anArray){ //equal 
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            if(Data[i] != anArray.get(i)){
                return false;
            }
        }return true;
    }
    return false;
}

intArray & intArray::operator +(intArray &anArray){ //add 
    intArray *temp;
    temp = new intArray(anArray);
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

intArray & intArray::operator -(intArray &anArray){ //subtract     intArray & operator-(intArray & rhs);
    intArray *temp;
    temp = new intArray(anArray);
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


intArray & intArray::operator++(){ //Prefix
	for(int i = 0; i < Size; i++){
		this -> Data[i] = Data[i] + 1;
	}
	return *this;
}

intArray & intArray::operator++(int dummy){ //Postfix
  for(int i = 0; i < Size; i++){
    this -> Data[i] = Data[i] + 1;
  }
  return *this;
}

void intArray::insert (int index, int value){
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

int intArray::remove (int index){
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

ostream & operator<<(ostream & outStream, intArray &anArray){
	for(int i = 0; i < anArray.size(); i++){
        cout << " " << anArray.get(i) << " " ;
    }
  return cout << endl;
}

istream & operator>>(istream & inStream, intArray &anArray){
	for(int i = 0; i < anArray.size(); i++){
		int value;
	  cout << "enter a value " << endl;
        cin >> value;
		anArray.set(i, value);
    }
} 

void intArray::Print(){
    for(int i = 0; i < Size; i++){
        cout << " " << Data[i] << " " ;
    }
    cout << endl;
}
