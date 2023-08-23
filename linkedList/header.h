#include<iostream>
using namespace std;

//forward declaration
class List;

class Node{
    int data;
    
    public :
    Node* next;

    Node(int d):data(d),next(0){}

    ~Node(){
        if(next!=NULL){
            delete next;
            next = NULL;
        }
        cout<<"deleting node with data : "<<data<<endl;
    }

    int getData(){
        return data;
    }

    friend class List;
};

class List{
    Node* head;
    Node* tail;
    
    //helper method
    int searchHelper(Node* start,int key){
        //base case
        if(start->next == 0){
            return -1;
        }

        if(start->data == key){
            return 0;
        }

        //rec case
        int subIdx = searchHelper(start->next,key);
        if(subIdx == -1){
            return -1;
        }
        return subIdx+1;
    }
    
    public :
    List():head(0),tail(0){}         //(0 == NULL)

    Node* getbegin(){
        return head;
    }

    //push front
    void push_front(int data){
        if(head == 0){
            Node* n = new Node(data);
            head = tail = n;
        }
        else{
            Node* n  = new Node(data);
            n->next = head;
            head = n;
        }
    }

    //push back
    void push_back(int data){
        if(head == 0){
            Node* n = new Node(data);
            head = tail = n;
        }
        else{
            Node* n = new Node(data);
            tail->next = n;
            tail = n;
        }
    }

    //insert method
    void insert(int data,int pos){
        if(pos == 0){
            push_front(data);
            return;
        }

        //otherwise
        Node* temp = head;

        for(int jump=1;jump<=pos-1;jump++){
            temp = temp->next;
        }

        Node* n = new Node(data);
        n->next = temp->next;
        temp->next = n;    
    }

    //searching
    int searching(int key){
        Node* temp = head;
        int idx = 0;
        while(head!=0){
            if(temp->data == key){
                return idx;
            }
            idx++;

            temp = temp->next;
        }
        return -1;
    }

    //recursive search
    int recursiveSearch(int key){
        int idx = searchHelper(head,key);
        return idx;      
    }

    //POP Front
    void popFront(){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    //deleting middle node
    void deleteNode(int pos){
        Node * temp = head;
        for(int jump=1;jump<=pos-1;jump++){
            temp = temp->next;
        }

        Node* local = temp->next;
        temp->next = local->next;
        local->next = NULL;
        delete local;
    }

    //deletion
   /* ~List(){
        if(head!=NULL){
            delete head;
            head = NULL;
        }
    }*/
};