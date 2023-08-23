#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();

    char sentence[1000];
    char largest[1000];
    
    int largestLength =0;
    while(n--){
        cin.getline(sentence,1000);
        //cout<<sentence<<endl;
        int length = strlen(sentence);
        if(length>largestLength){
            largestLength = length;
             strcpy(largest,sentence);
        }
    }
    cout<<"Largest string is : "<<largest<<endl;

    return 0;
}