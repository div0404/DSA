#include<iostream>
using namespace std;

int factorial(int n){
    int factno=1;
    for(int i=2;i<=n;i++){
        factno*=i;
    }
    return factno;
}
int main(){
    int n,r;
    cin>>n>>r;

    int ans = factorial(n)/(factorial(n-r)*factorial(r));
    cout<<ans<<endl;

    return 0;
}