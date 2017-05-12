/* 
 * File:   main.cpp
 * Author: diego valdes
 *
 * Created on September 24, 2015, 3:53 PM
 */

#include <cstdlib>

#include "mySudoku.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
    int row, number;
    int Data[9][9];
    for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                Data[x][y] = 0;
            }
        } 

    mySudoku start;
    start.PrintPuzzle();
    cout << " \n";
    mySudoku start1(Data);
    start1.PrintPuzzle();
    cout << "Read puzzle" << endl;
    start1.ReadPuzzle();
    cout << "Print Puzzle start1" << endl;
    start1.PrintPuzzle();
    cin >> row >> number;
    bool test = start1.CheckRow(5, 2);
    bool test2 = start1.CheckCol(4, 8);
    cout << test << test2 << endl;
    bool test3 = start1.CheckSubBox(3,3,4);
    start1.SolvePuzzle(-1);
    start1.PrintPuzzle();

    return 0;
}

