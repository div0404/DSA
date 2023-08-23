#include<iostream>
using namespace std;

void findingSubsets(char *input,char *output,int i,int j){
    //base case
    if(input[i] == '\0'){
        output[j] = '\0';
        if(output[0] == '\0'){
            cout<<"Null";
        }
        cout<<output<<endl;
        return;
    }

    //rec case
    //include ith element
    output[j] = input[i];
    findingSubsets(input,output,i+1,j+1);

    //exclude ith element
    findingSubsets(input,output,i+1,j);

}

int main(){
    char input[100];
    char output[100];

    cin>>input;

    findingSubsets(input,output,0,0);

    return 0;
}