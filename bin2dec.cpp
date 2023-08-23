#include<iostream>
using namespace std;

int binarytodecimal(int n){
    int base = 1;
    int ans = 0;
    while(n>0){
        int lastdigit = n%10;
        ans += base*lastdigit;
        base *=2;
        n/=10;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;

    cout<<binarytodecimal(n)<<endl;

    return 0;
}