#include<iostream>
#include<cstring>
using namespace std;

//using strtok
int main(){
    char input[1000];
    cin.getline(input,1000);

    char* token  = strtok(input," ");
    while(token!=NULL){
        cout<<token<<endl;
        token = strtok(NULL," ");
    }

    return 0;
}