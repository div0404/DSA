#include<iostream>
using namespace std;

int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    int M1[n1][n2];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin>>M1[i][j];
        }
    }

    int M2[n2][n3];
    for(int i=0;i<n2;i++){
        for(int j=0;j<n3;j++){
            cin>>M2[i][j];
        }
    }

    int ans[n1][n3];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            ans[i][j] = 0;
        }cout<<endl;
    }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            for(int k=0;k<n2;k++){
                ans[i][j] += M1[i][k]*M2[k][j];
            }
        }
    }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            cout<<ans[i][j]<<" ";
        }cout<<endl;
    }

    return 0;
}