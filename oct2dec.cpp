#include<iostream>
using namespace std;

int octaltodecimal(int n){
    int ans =0;
    int base =1;
    while(n>0){
        int lastdigit = n%10;
        ans += base*lastdigit;
        base*=8;
        n/=10;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;

    cout<<octaltodecimal(n)<<endl;

    return 0;
}