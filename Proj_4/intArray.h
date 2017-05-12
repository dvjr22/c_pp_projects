/* 
 * File:   intArray.h
 * Author: Diego Valdes
 *
 * Created on October 28, 2015, 4:33 PM
 */

#ifndef INTARRAY_H
#define	INTARRAY_H

class intArray {
public:
    intArray(); //tested
    intArray(int ArraySize, int value); //tested
    intArray(int anArray[], int ArraySize);  //tested
    virtual ~intArray();
    
    int size() const; //tested
    void set(int index, int value); //tested
    int get(int index) const; //tested
    void copy(const intArray  &anArray) const; //tested
    bool equal(const intArray &anArray) const; //tested
    void add(const intArray &anArray) const; //tested
    void subtract(intArray anArray); //tested
    void printArray(); //tested
    
private:
    int const Size;
    int *Data;

};

#endif	/* INTARRAY_H */

