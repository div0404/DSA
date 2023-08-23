#include<iostream>
#include "header.h"
using namespace std;

void reverse(Node* &head){
    Node* C = head;
    Node* p = NULL;
    Node* N;

    while(C!=NULL){
        //store the address of next node
        N = C->next;
        //make the current node point to prev
        C->next = p;
        //upadte prev and the current
        p = C;
        C = N;
    }
    head = p;
}

int main(){
    Node* head;
    //cin>>head;
    cout<<head;
    reverse(head);
    cout<<head;
}