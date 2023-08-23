#include<iostream>
using namespace std;

void wordSpell(int n){
    string arr[] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    
    //base case
    if(n==0){
        return;
    }

    int lastDigit = n%10;
    wordSpell(n/10);
    cout<<arr[lastDigit]<<" ";
}

int main(){
    int n;
    cin>>n;

    wordSpell(n);

    return 0;
}