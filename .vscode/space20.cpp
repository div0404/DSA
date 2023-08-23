#include<iostream>
#include<cstring>
using namespace std;

char replace_space(char *input){
    int space = 0;
    for(int i=0;input[i]!=0;i++){
        if(input[i]==' '){
            space++;
        }
    }

    int idx = strlen(input) + 2*space;
    input[idx] = '\0';
    for(int i=strlen(input)-1;i>=0;i--){
        if(input[i] == ' '){
            input[idx-1] = '0';
            input[idx-2] = '2';
            input[idx-3] = '%';
            idx = idx-3;
        }
        else{
            input[idx-1] = input[i];
            idx--;
        }
    }
}

int main(){
    char input[1000];
    cin.getline(input,1000);
    replace_space(input);
    cout<<input<<endl;

    return 0;
}