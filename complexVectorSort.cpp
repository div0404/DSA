#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int totalMarks(vector<int> marks){
    return marks[0] + marks[1] + marks[2];
}

bool compare(pair<string,vector<int>> s1,pair<string,vector<int>> s2){
    vector<int> m1 = s1.second;
    vector<int> m2 = s2.second;
    return totalMarks(m1)>totalMarks(m2);
}

int main(){
    vector<pair<string,vector<int>>> studentMarks = {
        {"Rohan",{10,20,11}},
        {"Prateek",{10,21,5}},
        {"Jagrat",{4,5,6}},
        {"Suyash",{10,13,20}}
    };

    sort(studentMarks.begin(),studentMarks.end(),compare);

    for(auto s : studentMarks){
        cout<<s.first<<" "<<totalMarks(s.second)<<endl;
    }

    return 0;
}