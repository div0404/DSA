#include<iostream>
using namespace std;

int main(){
    char ch = cin.get();
    int alpha=0;
    int space =0;
    int digits =0;

    while(ch != '\n'){
        
        if((ch>='a' and ch<='z') || (ch>='A' and ch<='Z')){
            alpha++;
        }
        else if(ch==' '){
            space++;
        }
        else if(ch>='1' and ch<='9'){
            digits++;
        }
        ch = cin.get();
    }
    cout<<"alpha "<<alpha<<endl;
    cout<<"space "<<space<<endl;
    cout<<"digits "<<digits<<endl;
    
    return 0;
}