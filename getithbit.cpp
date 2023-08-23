#include<iostream>
using namespace std;

//get ith bit
int getithbit(int n,int position){
    int mask = 1<<position;
    return (n & mask) > 0 ? 1 : 0;
}

//set ith bit
void setithbit(int &n,int position){
    int mask = (1<<position);
    n = (n | mask);
}

//clear ith bit
void clearithbit(int &n,int position){
    int mask = ~(1<<position);
    n = (n & mask);
}

//update ith bit
void updateithbit(int &n,int position,int value){
    clearithbit(n,position);
    int mask = value<<position;
    n = (n | mask);
}

//clear last i bits
void clearLastIbits(int &n,int position){
    int mask = -1<<position;
    n = (n&mask);
}

int main(){
    int n = 15;
    int position;
    cin>>position;
   
    //cout<<getithbit(n,position)<<endl;
    
    setithbit(n,position);
    //cout<<n<<endl;

    clearithbit(n,position);
    //cout<<n<<endl;

    updateithbit(n,position,1);
    //cout<<n<<endl;

    clearLastIbits(n,2);
    cout<<n<<endl;

    return 0;
}