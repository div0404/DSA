#include<iostream>
using namespace std;

void clearRange(int &n,int i,int j){
    int a = -1<<(j+1);
    int b = (1<<i) - 1;
    int mask = a | b;
    n = n & mask; 
}

void replaceBits(int &n,int i,int j,int m){
    clearRange(n,i,j);
    int mask = m<<i;
    n = n | mask;
}

int main(){
    int n;
    cin>>n;

    replaceBits(n,1,3,2);
    cout<<n<<endl;
    return 0;
}