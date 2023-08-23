#include<iostream>
using namespace std;

void clearRange(int &n,int i,int j){
    int a = -1<<(j+1);
    int b = (1<<i) - 1;
    int mask = a | b;
    n = n & mask; 
}

int main(){
    int n;
    cin>>n;
    clearRange(n,1,3);
    cout<<n<<endl;

    return 0;
}