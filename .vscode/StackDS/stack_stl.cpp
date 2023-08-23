#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> books;

    books.push("c++");
    books.push("java");
    books.push("python");
    books.push("JS");
    books.push("css");

    while(!books.empty()){
        cout<<books.top()<<endl;
        books.pop();
    }

    return 0;
}