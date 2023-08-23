#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(string s1,string s2){
    if(s1.length()==s2.length()){
        return s1<s2;
    }
    return s1.length()<s2.length();
}

void subsequence(string input,string o,vector<string> &v){
    //base case
    if(input.length()==0){
        v.push_back(o);
        return;
    }

    char ch = input[0];
    string reduced_input = input.substr(1);

    //include
    subsequence(reduced_input,o + ch,v);
    //exclude
    subsequence(reduced_input,o,v);
}

int main(){
    string s;
    cin>>s;

    string output = "";
    vector<string> v;
    subsequence(s,output,v);

    //sorting
    sort(v.begin(),v.end(),compare);

    for(auto s : v){
        cout<<s<<",";
    }
    cout<<endl;

    return 0;
}