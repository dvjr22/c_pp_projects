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

intArray::intArray(int anArray[], int ArraySize) : Size(ArraySize){ ///
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

int intArray::get(int index) const{
    return Data[index];
}

void intArray::set(int index, int value){
    Data[index] = value;
}

void intArray::copy(const intArray &anArray) const{
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            Data[i] = anArray.get(i);
        }
    }else{
        exit (0);
    }
    
}

bool intArray::equal(const intArray &anArray) const{
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            if(Data[i] != anArray.get(i)){
                return false;
            }
        }return true;
    }
    return false;
}

void intArray::add(const intArray &anArray) const{
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            int result = Data[i] + anArray.get(i);
            Data[i] = result;
        }
    }else{
        exit (0);
    }
}

void intArray::subtract(intArray anArray){
    if(Size == anArray.size()){
        for(int i = 0; i < Size; i++){
            int result = Data[i] - anArray.get(i);
            Data[i] = result;
        }
    }else{
        exit (0);
    }
}

void intArray::printArray(){
    for(int i = 0; i < Size; i++){
        cout << " " << Data[i] << " " ;
    }
}
