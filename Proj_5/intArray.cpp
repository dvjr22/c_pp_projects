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

intArray::~intArray() {
  delete [] Data;
}

int intArray::size() const{
    return Size;
}

int intArray::get(int index){
    return Data[index];
}

void intArray::set(int index, int value){
    Data[index] = value;
}

void intArray::operator =(intArray &anArray){ //copy
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            Data[i] = anArray.get(i);
        }
    }else{
        exit (0);
    }    
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

void intArray::operator +(intArray &anArray){ //add
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            int result = Data[i] + anArray.get(i);
            Data[i] = result;
        }
    }else{
        exit (0);
    }
}

void intArray::operator -(intArray &anArray){ //subtract
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            int result = Data[i] - anArray.get(i);
            Data[i] = result;
        }
    }else{
        exit (0);
    }
}
void intArray::insert (int index, int value){
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

void intArray::printArray(){
    for(int i = 0; i < Size; i++){
        cout << " " << Data[i] << " " ;
    }
    cout << endl;
}
