#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    string key;
    T value;
    Node * next;

    Node(string key,T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
    ~Node(){
        if(next!=NULL){
            delete next;
        }
    }
};

template<typename T>
class HashTable{
    Node<T> ** table;
    int cs;
    int ts;

    int hashfn(string key){
        int idx = 0;
        int power = 1;

        for(auto ch : key){
            idx = (idx + power*ch)%ts;
            power = (power*29)%ts;
        }
        return idx;
    }

    void rehash(){
        //save the ptr to the oldtable and insert in new table
        Node<T> ** oldTable = table;
        int oldts = ts;

        //increase the table size
        cs = 0;
        ts = ts*2 + 1;
        table = new Node<T> * [ts];

        for(int i=0;i<ts;i++){
            table[i] = NULL;
        }

        //copy elements from oldtable to new table
        for(int i=0;i<oldts;i++){
            Node<T> * temp = oldTable[i];

            while(temp != NULL){
                string key = temp->key;
                T value = temp->value;
                insertion(key,value);
                temp = temp->next;
            }

            //destry the ith linkedlist
            if(oldTable[i] != NULL){
                delete oldTable[i];
            }
        }

        delete [] oldTable;
    }

    public:
    HashTable(int default_size = 7){
        cs = 0;
        ts = default_size;
        table = new Node<T>* [ts];

        for(int i=0;i<ts;i++){
            table[i] =  NULL;
        }
    }

    void insertion(string key,T value){
        int idx = hashfn(key);
        Node<T>* n = new Node<T>(key,value);

        //Insertion at the head of the linked list
        n->next = table[idx];
        table[idx] = n; 

        cs++;

        float load_factor = cs/ts;
        if(load_factor > 0.7){
            rehash();
        }
    }

    void print(){
        for(int i=0;i<ts;i++){
            cout<<"Bucket "<<i<<"->";

            Node<T> * temp = table[i];

            while(temp!=NULL){
                cout<<temp->key<<"->";
                temp = temp->next;
            }

            cout<<endl;
        }
    }

    T* search(string fruit){
        int idx = hashfn(fruit);

        Node<T>* temp = table[idx];

        while(temp!=NULL){
            if(temp->key == fruit){
                return & temp->value;
            }
            temp = temp->next;
        }
        return NULL;
    }
};