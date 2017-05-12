/* 
 * File:   mySudoku.cpp
 * Author: diego
 * 
 * Created on September 24, 2015, 3:55 PM
 */

#include "mySudoku.h"
#include <iostream>

using namespace std;

mySudoku::mySudoku() {
    for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                Data[x][y] = 0;
            }
        } 
}

mySudoku::mySudoku(int anArray[][Size]) {
    for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                Data[x][y] = anArray[x][y];
            }
        } 
}

mySudoku::~mySudoku() {
}

    void mySudoku::ReadPuzzle(){
        cout <<"Please enter the values of the Sudoku puzzle" << endl;
        for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                int a;
                cin >> a;
                Data[x][y] = a;
            }
        }     
    }
  
    void mySudoku::PrintPuzzle(){
        for(int y = 0; y < 9; y++){
            for(int x = 0; x < 9; x++){
                cout << " " << Data[x][y] << " ";
                if(x==8) cout << endl;
            }
        } 
    }
    
    bool mySudoku::CheckRow(int row, int number){
        int c;
        for(int i = 0; i < 9; i++){
            int c = Data[i][row];
            if(c==number){
                return true;
            }
    }
        return false;
    }
    
    bool mySudoku::CheckCol(int col, int number){
        int c;
        for(int i = 0; i < 9; i++){
            int c = Data[col][i];
            if(c==number){
                return true;
            }
            }
        return false;
        }

bool mySudoku::CheckZero(int anArray[][Size]){
  int check = 0;
  for(int i=0; i<9; i++){
    for(int j=0; j<9; j++){
      if(anArray[i][j] == check){
        return true;
      }
    }
  }
  return false;
}
    

bool mySudoku::CheckSubBox(int row, int col, int number){
  int a = (row%3*10) + (col%3);
  if(a == 0){
    for(int i =  col; i < col+3; i++){
      for(int j = row; j < row+3; j++){
        if(Data[i][j] == number){
          return true;
        }
      }
    }
    return false;
  }
  
  if(a ==20){
    for(int i =  col; i < col+3; i++){
        for(int j = row; j > row-3; j--){
          if(Data[i][j] == number){
            return true;
          }
        }
      }
    return false;
  }
  
  if(a==2){
    for(int i =  col; i > col-3; i--){
      for(int j = row; j < row+3; j++){
        if(Data[i][j] == number){
          return true;
        }
      }
    }
    return false;
  }
  
  if(a==22){
    for(int i =  col; i > col-3; i--){
      for(int j = row; j > row-3; j--){
        if(Data[i][j] == number){
          return true;
        }
      }
    }
    return false;
  }
  
  if(a==10){
    for(int i =  col; i < col+3; i++){
      for(int j = row-1; j < row+2; j++){
        if(Data[i][j] == number){
          return true;
        }
      }
    }
    return false;
  }
  
  if(a==12){
    for(int i =  col; i > col-3; i--){
      for(int j = row-1; j < row+2; j++){
        if(Data[i][j] == number){
          return true;
        }
      }
    }
    return false;
  }
  
  if(a==11){
    for(int i =  col-1; i < col+2; i++){
      for(int j = row-1; j < row+2; j++){
        if(Data[i][j] == number){
          return true;
        }
      }
    }
    return false;
  }
  
  if(a==21){
    for(int i =  col-1; i < col+2; i++){
      for(int j = row; j > row-3; j--){
        if(Data[i][j] == number){
          return true;
        }
      }
    }
    return false;
  }
  
  if(a==1){
    for(int i =  col-1; i < col+2; i++){
      for(int j = row; j < row+3; j++){
        if(Data[i][j] == number){
          return true;
        }
      }
    }
    return false;
  }
}

int mySudoku::SolvePuzzle(int iterations){
  if(iterations > 0){
    int c = 1;
    int t = 0;
    int number;
    while(t < iterations){
      t++;
      for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
          if(Data[i][j] == 0){
            c=0;
            for(int n = 1; n < 10; n++){
              bool x = CheckRow(j, n);
              bool y = CheckCol(i, n);
              bool z = CheckSubBox(j, i, n);
              if(x == 0 && y == 0 && z == 0){
                number = n;
                c++;
              }
            }
            if(c==1){
              Data[i][j] = number;
              c = 0;
            }
          }
        }
      }
      t++;
      cout << "iteration " << t << endl;
    }
  }
  
  if(iterations == 0){
    cout << "Will not do anything to the puzzle." << endl;
  }
  
  if(iterations < 0){
    int c = 1;
    int t = 0;
    int number;
    bool test = CheckZero(Data);
    while(test == true){
      t++;
      for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
          if(Data[i][j] == 0){
            c=0;
            for(int n = 1; n < 10; n++){
              bool x = CheckRow(j, n);
              bool y = CheckCol(i, n);
              bool z = CheckSubBox(j, i, n);
              if(x == 0 && y == 0 && z == 0){
                number = n;
                c++;
              }
              }
              if(c==1){
                Data[i][j] = number;
                c = 0;
                  }
          }
        }
      }
      test = CheckZero(Data);
    cout << "iteration " << t << endl;
    }
}
  
}
