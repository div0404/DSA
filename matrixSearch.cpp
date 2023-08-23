#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int key;
    cin>>key;
    
    int M[n][m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>M[i][j];
        }
    }

   //row - 3 col - 0
    //M[3][0] = 10 flag=true;
    //r-3 c-0
    //M[3][0] = 10 flag=true;
    
    
    
    int r=0;
    int c=m-1;
    bool flag=false;

    while(r<n && c>=0){
        if(M[r][c]==key){
            flag=true;
            break; //if element found break the loop
        }
        else if(M[r][c]<key){
            r++;
        }
        else{
            c--;
        }
    }
    if(flag){
        cout<<" Element found"<<endl;
    }
    else{
        cout<<" Element not found"<<endl;
    }

    return 0;
}