#include<iostream>
#include<cstring>
#include<vector>
#include<sstream>
using namespace std;

//tokenisation using sstream
int main(){
    string input;
    getline(cin,input);

    //creating stringstream object
    stringstream s(input);
    string token;
    vector<string> tokens;

    while(getline(s,token,' ')){
        tokens.push_back(token);
    }

    for(auto token : tokens){
        cout<<token<<",";
    }
    
    return 0;
}