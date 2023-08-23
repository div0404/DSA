#include<iostream>
using namespace std;

int main(){
    char sentence[1000];
    char temp = cin.get();
    int len = 1;
    
    while (temp != '\n'){
        len++;
        cout<<temp;
        //update input 
        temp = cin.get();
    }cout<<endl;
    cout<<"length : "<<len<<endl;

    return 0;
}