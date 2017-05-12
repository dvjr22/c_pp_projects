/* 
 * File:   main.cpp
 * Author: Diego Valdes
 *
 * Created on October 28, 2015, 4:28 PM
 */

#include <cstdlib>
#include "intArray.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int TAS = 10;
    int TestArray[TAS];
    for(int i = 0; i < TAS; i++){
        TestArray[i] = i * TAS;
    }  
    int TestArray1[TAS];
    for(int i = 0; i < TAS; i++){
      TestArray1[i] = i * TAS+(2*i);
    }
    cout << endl;
    cout << "Printing TestArray " << endl;
    for(int i = 0; i < TAS; i++){
      cout << TestArray[i] << " " ;
    }
    cout << endl;

    cout << "Testing default constructor:" << endl;
    
    intArray test;
    cout << "Printing Array object " << endl;
    test.printArray();
    cout << endl;
    
    cout << "Testing alternate constructor intArray(10, 10)" << endl;
    
    intArray test1(10, 10);
    cout << "Printing Array object " << endl;
    test1.printArray();
    cout << "The value at 5 is " << test1.get(5) << endl;
    test1.set(5, 52);
    cout << "The value at 5 after test1.set(5, 52)... " << test1.get(5) << endl;
    cout << "The size of this array is " << test1.size() << endl;
    cout << endl;
    
    cout << "Testing 2nd default constructor intArray(TestArray, 10)" << endl;
    
    cout << "Printing TestArray " << endl;
    for(int i = 0; i < TAS; i++){
      cout << TestArray[i] << " " ;
    }
    cout << endl;
    intArray test2(TestArray, TAS);
    cout << "Printing Array object " << endl;
    test2.printArray();
    cout << endl;
    cout << "The value at 5 is " << test2.get(5) << endl;
    test2.set(5, 25);
    cout << "The value at 5 after test2.set(5,25)... " << test2.get(5) << endl;
    cout << "The size of this array is " << test2.size() << endl;
    cout << endl;
    
    cout << "Testing copy method" << endl;
    
    cout << endl;
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "Printing test 2 object:" << endl;
    test2.printArray();
    cout << "Copying test1 to test2." << endl;
    test1 = test2;
    cout << "Printing test1 objects after copy." << endl;
    test1.printArray();
    cout << "Printing test2 objects after copy." << endl;
    test2.printArray();
    cout << endl;
    
    cout << "Testing add and subtract methods" << endl;
    
    cout << endl;
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "Printing test 2 object:" << endl;
    test2.printArray();
    cout << "Adding test1 and test 2." << endl;
    test1 + test2;
    cout << "Printing test1 objects after adding." << endl;
    test1.printArray();
    cout << "Printing test2 objects after adding." << endl;
    test2.printArray();
    cout << endl;
    cout << "Subtracting test1 and test 2." << endl;
    test1 - test2;
    cout << "Printing test1 objects after subtracting." << endl;
    test1.printArray();
    cout << "Printing test2 objects after subtracting." << endl;
    test2.printArray();
    cout << "Subtracting test2 and test1." << endl;
    test2 - test1;
    cout << "Printing test1 objects after subtracting." << endl;
    test1.printArray();
    cout << "Printing test2 objects after subtracting." << endl;
    test2.printArray();
    cout << endl;
    
    cout << "Testing equals method" << endl;
    
    cout << endl;
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "Printing test 2 object:" << endl;
    test2.printArray();
    bool t1 = test1 == test2;
    cout << "The result of your first test is..." << t1 << endl;
    cout << "Making test1 and test2 to be equal." << endl;
    test2 = test1;
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "Printing test 2 object:" << endl;
    test2.printArray();
    test1 = test2;
    bool t2 = test1 == test2;
    cout << "The result of your second test is..." << t2 << endl;
    cout << endl;
    
    cout << "Testing insert method" << endl;
    
    cout << endl;
    cout << "Reseting TestArray" << endl;
    for(int i = 0; i < 10; i++){
      test1.set(i, i*10);
    }
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "inserting test1.insert(5, 101)" << endl;
    test1.insert(5, 101);
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "inserting test1.insert(4, 33)" << endl;
    test1.insert(4, 33);
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "The size of this array after both additions is " << test1.size() << endl;
    cout << endl;
    
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "Deleting test1.remove(2)" << endl;
    int x = test1.remove(2);
    cout << "The value removed with test1.remove(2) was " << x <<endl;
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "Deleting test1.remove(8)" << endl;
    int y = test1.remove(8);
    cout << "The value removed with test1.remove(8) was " << y <<endl;
    cout << "Printing test 1 object:" << endl;
    test1.printArray();
    cout << "The size of this array after both deletes is " << test1.size() << endl;


    return 0;
}

