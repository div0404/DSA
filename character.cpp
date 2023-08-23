#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char arr[] = "xytdftfu"; //{'a','d','g','s','\0'};
    
    cout<<strlen(arr)<<endl;
    cout<<sizeof(arr)<<endl;   // +1 for null character

    char arrr[100];
    cin>>arrr;
    cout<<arrr;
    return 0;
}