#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//comparator
bool compare(string a,string b){
    if(a.length() == b.length()){
        return a<b; // lexographically
    }
    return a.length()<b.length();
}

void findingSubsets(char *input,char *output,int i,int j,vector<string> &list){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';
        string temp(output);
        list.push_back(temp);

        return;
    }    

    //rec case

    //including ith element
    output[j] = input[i];
    findingSubsets(input,output,i+1,j+1,list);

    //excluding ith element
    findingSubsets(input,output,i+1,j,list);

}

int main(){
    char input[100];
    cin>>input;

    char output[100];

    vector<string> list;

    findingSubsets(input,output,0,0,list);

    //sorting o/p
    sort(list.begin(),list.end(),compare);

    for(auto s : list){
        cout<<s<<",";
    }
    
    return 0;
}