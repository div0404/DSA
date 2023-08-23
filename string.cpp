#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char a[1000] = "apple";
    char b[1000];
    
    //string length
    cout<<strlen(a)<<endl;

    //string copy
    strcpy(b,a);
    cout<<b<<endl;

    //string concat
    char c[1000] = "Divyansh ";

    char d[200] = "Singh";

    cout<<strcat(c,d)<<endl;

    //string compare
    cout<<strcmp(a,b)<<endl;
    cout<<strcmp(c,d)<<endl;
    
    return 0;
}