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
    int TAS = 15;
    int TAS2 = 10;
    int TestArray[TAS];
    for(int i = 0; i < TAS; i++){
        TestArray[i] = i * TAS;
    }
    
    cout << endl;
    cout << "Printing TestArray " << endl;
    for(int i = 0; i < TAS; i++){
      cout << TestArray[i] << " " ;
    }
    cout << endl;
    
    int TestArray2[TAS2];
    for(int i = 0; i < TAS2; i++){
        TestArray2[i] = i * TAS2;
    }
    cout << endl;
    
    cout << "Printing TestArray2 " << endl;
    for(int i = 0; i < TAS2; i++){
      cout << TestArray2[i] << " " ;
    }
    cout << endl;
    cout << endl;
    
    cout << "Testing default constructor:" << endl;
    intArray test;
    test.printArray();
    cout << endl;
    
    cout << "Testing alternate constructor intArray(int, int)" << endl;
    intArray test1(10, 10);
    test1.printArray();
    cout << endl;
    cout << "The value at 5 is " << test1.get(5) << endl;
    test1.set(5, 52);
    cout << "The value at 5 after test1.set(5, 52)... " << test1.get(5) << endl;
    cout << "The size of this array is " << test1.size() << endl;
    cout << endl;
    
    cout << "Testing 2nd default constructor intArray(int [], int)" << endl;
    intArray test2(TestArray, TAS);
    test2.printArray();
    cout << endl;
    cout << "The value at 5 is " << test2.get(5) << endl;
    test2.set(5, 25);
    cout << "The value at 5 after test2.set(5,25)... " << test2.get(5) << endl;
    cout << "The size of this array is "<< test2.size() << " and is... " << TAS << endl;
    cout << endl;
    
    cout << "Testing copy method" << endl;
    int TestArray3[TAS2];
    for(int i = 0; i < TAS2; i++){
      TestArray3[i] = i * TAS2+2;
    }
    cout << "Printing TestArray2 " << endl;
    for(int i = 0; i < TAS2; i++){
      cout << TestArray2[i] << " " ;
    }
    cout << endl;
    cout << endl;
    cout << "Printing TestArray3 " << endl;
    for(int i = 0; i < TAS2; i++){
      cout << TestArray3[i] << " " ;
    }
    cout << endl;
    cout << endl;
    intArray test3(TestArray2, TAS2);
    intArray test4(TestArray3, TAS2);
    cout << "Printing TestArray 3 object: " << endl;
    test3.printArray();
    cout << endl;
    cout << endl;
    cout << "Printing TestArray 4 object: " << endl;
    test4.printArray();
    cout << endl;
    cout << endl;
    cout << "Now copying " << endl;
    test3.copy(test4);
    cout << " " << endl;
    cout << "Printing TestArray 3 object after copy: " << endl;
    test3.printArray();
    cout << endl;
    cout << endl;
    cout << "Printing TestArray 4 object ater copy: " << endl;
    test4.printArray();
    cout << endl;
    cout << endl;
 
    cout << "Testing equal" << endl;
    bool equals = test3.equal(test4);
    cout << "the result of your test is (Test 3 to Test 4)..." << equals << endl;
    equals = test1.equal(test4);
    cout << "the result of your test is (Test 1 to Test 4)..." << equals << endl;
    cout << "Changing test3.set(5, 100)" << endl;
    test3.set(5,100);
    equals = test3.equal(test4);
    cout << "the result of your test is (Test 3 to Test 4) now is..." << equals << endl;
    cout << " " << endl;
    
    cout << "Testing add" << endl;
    cout << "Printing TestArray 3 object: " << endl;
    test3.printArray();
    cout << endl;
    cout << "Printing TestArray 4 object: " << endl;
    test4.printArray();
    cout << endl;
    cout << "Add (Test 3 and Test 4): " << endl;
    test3.add(test4);
    cout << "Printing TestArray 3 object: " << endl;
    test3.printArray();
    cout << endl;
    cout << endl;
    
    cout << "Testing subtract" << endl;
    for(int i = 0; i < 10; i++){
      test4.set(i, (i+3)*2);
    }
    cout << "Printing TestArray 3 object: " << endl;
    test3.printArray();
    cout << endl;
    cout << "Printing TestArray 4 object: " << endl;
    test4.printArray();
    cout << endl;
    cout << "Sub (Test 3 and Test 4): " << endl;
    test3.subtract(test4);
    cout << "Printing TestArray 3 object: " << endl;
    test3.printArray();
    cout << endl;
    cout << "Sub (Test 4 and Test 3): " << endl;
    test4.subtract(test3);
    cout << "Printing TestArray 4 object: " << endl;
    test4.printArray();
    cout << endl;

    return 0;
}

