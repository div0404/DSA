//string key sort
/*
Sample input
3
92 022
82 12
77 13
2 false numeric

Sample output
82 12
77 13 
92 022
*/

#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

string getstringAtKey(string str,int key){
    char* s = strtok((char*)str.c_str()," ");
    while(key>1){
        s = strtok(NULL," ");
        key--;
    }
    return (string)s;
}

int string2int(string str){
    int ans = 0;
    int p = 1;

    for(int i=str.length()-1;i>=0;i--){
        ans += str[i]*p;
        p *= 10;
    }
    return ans;
}

bool numericSort(pair<string,string> p1,pair<string,string> p2){
    string keys1 = p1.second;
    string keys2 = p2.second;
    return string2int(keys1)<string2int(keys2);
}

bool lexicoSort(pair<string,string> p1,pair<string,string> p2){
    string keys1 = p1.second;
    string keys2 = p2.second;

    return keys1<keys2;
}

int main(){
    int n;
    cin>>n;

    cin.get();  //to consume \n
    
    string input;
    vector<string> v;
    for(int i=0;i<n;i++){
        getline(cin,input);
        v.push_back(input);
    }

    int key;
    string reversal,ordering;
    cin>>key>>reversal>>ordering;

    //1. Extract the keys and store it
    vector<pair<string,string>> vp;
    string keys;
    for(int i=0;i<n;i++){
        keys = getstringAtKey(v[i],key);
        vp.push_back({v[i],keys});
    }

    //2. sorting
    if(ordering=="numeric"){
        sort(vp.begin(),vp.end(),numericSort);
    }
    else{
        sort(vp.begin(),vp.end(),lexicoSort);
    }

    //3. reverse
    if(reversal=="true"){
        reverse(vp.begin(),vp.end());
    }

    //4. output
    for(int i=0;i<n;i++){
        cout<<vp[i].first<<endl;
    }

    return 0;
}