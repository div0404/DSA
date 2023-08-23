#include<iostream>
using namespace std;

void decreasing(int n){
    //base case
    if(n==0){
        return;
    }
    //recursive case
    cout<<n<<",";
    decreasing(n-1);
}

void increasing(int n){
    //base case
    if(n==0){
        return;
    }

    increasing(n-1);
    cout<<n<<",";
}

int main(){
    int n;
    cin>>n;

    decreasing(n);
     cout<<endl;
    increasing(n);

    return 0;
}