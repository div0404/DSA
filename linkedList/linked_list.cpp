#include<iostream>
#include "header.h"
using namespace std;

int main(){
    List l;


    l.push_front(1);
    l.push_front(0);
    l.push_back(2);
    l.push_back(3);
    l.push_back(4);

    //l.insert(3,3);
    //l.insert(9,0);

    //l.popFront();
    l.deleteNode(3); 
    
    Node* head = l.getbegin();
    
    
    while(head != 0){
        cout<<head->getData()<<"->";
        head = head->next;
    }
    cout<<endl;

    //cout<<l.searching(2)<<endl;
    //cout<<l.recursiveSearch(2);

    

    return 0;
}