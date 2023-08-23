#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();

    char arr[n+1];
    cin.getline(arr,n);
    cin.ignore();
    
    int currLen = 0, maxLen = 0;
    for(int i=0;arr[i]!='\0';i++){
        if(arr[i]==' '){
            if(currLen>maxLen){
                maxLen = currLen;
            }
            currLen = 0;
        }
        else
        currLen++;
    }
    cout<<maxLen<<endl;

    return 0;
}