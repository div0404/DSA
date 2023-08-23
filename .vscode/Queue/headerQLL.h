
class Queue;

class Node{
    public:
    int data;
    Node * next;
    Node(int d){
        data = d;
    }
};

class Queue{
    Node* head;
    Node* tail;
    public:
    Queue(){
        head = 0;
        tail = 0;
    }
    
    bool empty(){
        return head == 0;
    }

    void push(int data){
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

    void pop(){
        if(!empty()){
            Node* temp = head;
            head = head->next;
            temp->next = 0;
            delete temp;
        }
    }

    int front(){
        return head->data;
    }
};