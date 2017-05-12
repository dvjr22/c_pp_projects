 /* 
 * File:   main.cpp
 * Author: Diego Valdes
 *
 * Created on October 28, 2015, 4:28 PM
 */

#include <cstdlib>
#include "Array.h"
#include <iostream>
#include "Array.cpp"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int TAS = 10;
    double TestArray[TAS];
    for(int i = 0; i < TAS; i++){
        TestArray[i] = i * 10.5;
    }

	Array<double> test1(10, 10);
  Array<double> test2(TestArray, TAS);
  Array<double> test3(10, 20);
  test1.Print();
  test2.Print();
  test3.Print();
  test3 = test1 + test2;
  test3.Print();
  test3 = test2 - test1;
  test3.Print();
  test1.remove(5);
  test1.Print();
  test1.insert(5, 45.3);
  test1.Print();
  test2.Print();
  test2++;
  ++test2;
  test2.Print();
  -test2;
  test2.Print();
  double a = test2.get(5);
  double b = test2[5];
  cout << "a is " << a << " and b is " << b << endl;  
  test2.set(5, 23.9);
  test2[6] = 23.9;
  cout << test2.get(5) << " " << test2.get(6) << endl;
  test1.Print();
  test2.Print();
  test1 += test2;
  test1.Print();
  test1 -= test2;
  test1.Print();
  bool c = test1 == test2;
  cout << c << endl;
  test1 = test2;
  test1.Print();
  test2.Print();
  c = test1 == test2;
  cout << c << endl;
  cout << "for the win!" << endl;
  cout << test1;
  cout << test2;
  cout << test3;

  

    return 0;
}

