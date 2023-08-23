#include<iostream>
using namespace std;

bool isSafe(int sudoku[][9],int n,int i,int j,int no){
    //check for row or col
    for(int k=0;k<n;k++){
        if(sudoku[k][j] ==no || sudoku[i][k] == no){
            return false;
        }
    }

    // check for subgrid
    int sx = (i/3)*3;
    int sy = (j/3)*3;

    for(int x=sx;x<sx+3;x++){
        for(int y=sy;y<sy+3;y++){
            if(sudoku[x][y] == no){
                return false;
            }
        }
    }
    return true;
}

void print(int sudoku[][9],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool solveSudoku(int sudoku[][9],int n,int i,int j){
    // base case
    if(i==n){
        //print the sudoku
        print(sudoku,n);
        return true;
    } 

    // rec case

    //at the end of the col
    if(j==n){
        return solveSudoku(sudoku,n,i+1,0);
    }

    //skip the prifilled value
    if(sudoku[i][j]!=0){
        return solveSudoku(sudoku,n,i,j+1);
    }

    //try out all possibilities
    for(int no=1;no<=9;no++){
    // whether safe or not    
      if(isSafe(sudoku,n,i,j,no)){
          sudoku[i][j] = no;
          bool subSolution = solveSudoku(sudoku,n,i,j+1);
          if(subSolution==true){
              return true;
            }
        }
    }
    //backtracking step
    sudoku[i][j] = 0;
    return false;   
}

int main(){
    int n = 9;
    int sudoku[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,0}
    };

    if(!solveSudoku(sudoku,9,0,0)){
        cout<<"Solution does not exist"<<endl;
    }

    return 0;
}
