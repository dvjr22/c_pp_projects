/* 
 * File:   mySudoku.h
 * Author: diego valdes
 *
 * Created on September 21, 2015, 12:53 PM
 */

#ifndef MYSUDOKU_H
#define	MYSUDOKU_H

const int Size(9);

class mySudoku {
public:
    mySudoku(); // 1 point
    mySudoku(int anArray[][Size]); // 1 points
    mySudoku(const mySudoku& orig);
    
    void ReadPuzzle(); // 2 points
    void PrintPuzzle(); // 2 points
    bool CheckRow(int row, int number); // 3 points, return true if the number exists
    bool CheckCol(int col, int number); // 3 points, return true if the number exists
    bool CheckSubBox(int row, int col, int number); // 5 points, retunrs true if the number exists
    int  SolvePuzzle(int iterations); // 10 points, iterates through the puzzle based on the paramter iterations
				      // if iterations = 0, then does nothing.
				      // if iterations is a positive integer then iteratively solves the puzzle
				      //    that many number of times
				      // if iterations = -1 (or any negative number), then it solves the puzzle
				      //    until convergence.
				      // return value is the number of iterations that the puzzle was solved.    	
    bool CheckZero(int anArray[][Size]);

    virtual ~mySudoku();
private:
    int Data[Size][Size];
};

#endif	/* MYSUDOKU_H */

