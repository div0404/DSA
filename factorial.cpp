#include<iostream>
using namespace std;

int factorial(int n){
    int facto = 1;
    for(int i=2;i<=n;i++){
        facto*=i;
    }
    return facto;
}
int main(){
    int n;
    cin>>n;
    int ans=factorial(n);
    cout<<ans<<endl;

    return 0;
}