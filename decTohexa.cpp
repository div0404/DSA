#include<iostream>
using namespace std;

string dec2hex(int n){
    int base = 1;
    string ans = " ";

    while(base<=n){
        base*= 16;
    }
    base/=16;

    while(base>0){
        int lastdigit = n/base;
        n -= lastdigit*base;        
        base/=16;

        if(lastdigit<=9){
            ans = ans + to_string(lastdigit);
        }
        else{
            char c = 'A' + lastdigit - 10;
        }
        return ans;     
    }

}
int main(){
    int n;
    cin>>n;

    cout<<dec2hex(n)<<endl;

    return 0;
}
//?????