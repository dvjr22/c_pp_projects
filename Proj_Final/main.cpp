 /* 
 * File:   main.cpp
 * Author: Diego Valdes
 *
 * Created on October 28, 2015, 4:28 PM
 */

#include <cstdlib>
#include "Array.h"
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

	Array test1(10, 10);
  Array test2(TestArray, TAS);
  Array test3(10, 20);
  cout << test1;
  cout << test2;
  test3 = test1 + test2;
  cout << test3;
  test2 = test3 - test1;
  cout << test2;
  ++test2;
  test2++;
  cout << test2;
	//cin >> test1; 
  cout << test1;
  cout << test2;
  cout << "+=" << endl;
  test1 += test2;
  cout << test1;
  cout << test2;
  cout << "-=" << endl;
  test2 -= test1;
  cout << test1;
  cout << test2;
  for(int i = 0; i < test1.size(); i++){
    int ex = test1[i];
    cout << ex << " ";
  }
  cout << endl;
  
  for(int i = 0; i < test1.size(); i++){
    test1[i]=i+1;
  }
  cout << test1;

  

    return 0;
}

