#include<iostream>
using namespace std;

void viewcount(int * viewsPtr){
    *viewsPtr = *viewsPtr + 1;
}

int main(){
    int views = 100;
    
    viewcount(&views);
    cout<<views<<endl;

    return 0;
}