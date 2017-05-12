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
	intArray(intArray &orig);
    virtual ~intArray();
    
    int size() const; //tested
    void set(int index, int value); //tested
    int get(int index); //tested
    void operator =(intArray  &anArray); //copy - tested
    bool operator ==(intArray &anArray); //equal - tested
    void operator +(intArray &anArray); //add - tested
    void operator -(intArray &anArray); //subtract - tested
    void insert (int index, int value); // tested
    int remove (int index); // tested
    void printArray(); 
    
private:
    int Size;
    int *Data;

};

#endif	/* INTARRAY_H */

