#include<iostream>
#include "headerQLL.h"
using namespace std;

int main(){
    Queue myQueue;

    myQueue.push(1);
    myQueue.push(2);
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    myQueue.push(6);

    myQueue.pop();
    myQueue.pop();

    while(!myQueue.empty()){
        cout<<myQueue.front()<<endl;
        myQueue.pop();
    }

    return 0;
}