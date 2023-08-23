#include<iostream>
using namespace std;

int** create2Darray(int rows,int cols){
    //array of pointers
    int** arr = new int*[rows];

    //memory allocation in each row
    for(int i=0;i<rows;i++){
        arr[i] = new int[cols];
    }

    //initialising the array
    int value =0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            arr[i][j] = value;
            value++;
        }
    }
    return arr;
}

int main(){
    int rows,cols;
    cin>>rows>>cols;

    int** arr = create2Darray(rows,cols);

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}