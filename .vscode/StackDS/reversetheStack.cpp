#include<iostream>
#include<stack>
using namespace std;

void insertBottom(stack<int> &s,int t){
    if(s.empty()){
        s.push(t);
        return;
    }

    int temp = s.top();
    s.pop();
    insertBottom(s,t);
    s.push(temp);
}

void reverseStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int t = s.top();
    s.pop();
    reverseStack(s);

    insertBottom(s,t);
}

int main(){
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    reverseStack(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
        
    }

    return 0;
}