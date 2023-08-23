#include<iostream>
using namespace std;

int main(){
    char arr[][100] = {
        "apple",
        "banana",
        "grapes",
        "mango"
    };

    //cout<<arr[2][1]<<endl;

     //print 2nd row
    //cout<<arr[1]<<endl;

    //print 2D character array
    for(int i=0;i<4;i++){
        cout<<arr[i]<<endl;
    }
    
    return 0;
}