#include<bits/stdc++.h>
using namespace std;

vector<int> increasingNumbers(int N) {
    //base case
    if(N==1){
        return 1;
    }
    
    //recursive case
    increasingNumbers(N);
    cout<<N<<endl;
}
int main(){
    int N=5;
    vector<int> increasingNumbers(N);
    
    return 0;
}