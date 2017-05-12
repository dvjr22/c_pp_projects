/* 
 * File:   intArray.h
 * Author: homayoun
 *
 * Created on October 21, 2015, 11:51 AM
 */

#ifndef INTARRAY_H
#define	INTARRAY_H
#include <iostream>
using namespace std;

class intArray {
public:
    intArray(); //tested
    intArray(int arraySize, int value); //tested
    intArray(int anArray[], int arraySize); //tested
    intArray(intArray &orig);
    virtual ~intArray(); //tested

    void Print(void); //tested
    intArray & operator=(intArray & rhs); //tested
    intArray & operator+(intArray & rhs); //tested
    intArray & operator-(intArray & rhs); //tested
    intArray & operator++(); //Prefix tested
    intArray & operator++(int dummy); //Postfix tested
    bool operator==(intArray & rhs); //tested

    void set(int index, int value); //tested
    int get(int index); //tested
    int size(); //tested
    void insert(int index, int value); //tested
    int remove(int index); //tested

    friend ostream & operator<<(ostream & outStream, intArray & rhs); // tested
    friend istream & operator>>(istream & inStream, intArray & rhs); // tested


private:
    int Size;
    int *Data;
};

#endif	/* INTARRAY_H */

