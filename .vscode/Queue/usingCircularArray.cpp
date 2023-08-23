#include<iostream>
#include "headerArr.h"
using namespace std;

int main(){
    Queue myQueue(7);

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);
    myQueue.push(7);
    myQueue.push(8);
    
    myQueue.pop();
    myQueue.pop();
    myQueue.pop();
    myQueue.push(10);

    while(!myQueue.empty()){
        cout<<myQueue.getfront()<<endl;
        myQueue.pop();
    }
    
    return 0;
}