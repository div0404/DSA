#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int main(){
    // string s; // = "apple";
    // getline(cin,s,'.');
    // cout<<s<<endl;

    // for(char ch : s){
    //     cout<<ch<<",";
    // }

    // //vector<string> ....

    int n = 5;
    
    vector<string> star;
    string s;

    while(n--){
        getline(cin,s);
        star.push_back(s);
    }
    for(string x : star){
        cout<<x<<endl;
    }

    return 0;
}