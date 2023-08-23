#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    int key;
    cin>>key;
    
    bool check = false;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==key){
                check = true;
                cout<<i<<" "<<j<<endl;
            }
        }
    }
    if(check){
        cout<<"key found"<<endl;
    }
    else{
        cout<<"key not found"<<endl;
    }

    return 0;
}