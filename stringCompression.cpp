#include<iostream>
using namespace std;

string stringCompression(string str){
    int n = str.length();
    string output;
    for(int i=0;i<n;i++){
        int count = 1;
        while(str[i]==str[i+1] and i<n-1){
            count++;
            i++;
        }
        output += str[i];
        output += to_string(count);
    }
    if(n>output.length()){
        return output;
    }
    else{
        return str;
    }
}
int main(){
    string s1 = "aaabbcccdd";
    string s2 = "abcd";

    cout<<stringCompression(s1)<<endl;
    cout<<stringCompression(s2)<<endl;

    return 0;
}