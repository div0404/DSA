#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    Node* left;
    Node* right;

    Node(int key){
        this->key = key;
        left = right = NULL; 
    }
};

Node* insert(Node* root,int key){
    if(root == NULL){
        return new Node(key);
    }
 //rec case
    if(key < root->key){
        root->left = insert(root->left,key);
    }
    else{
        root->right = insert(root->right,key);
    }

    return root;
}

void printInOrder(Node* root){
    if(root==NULL){
        return;
    }
    //left,root,right
    printInOrder(root->left);
    cout<<root->key<<" ";
    printInOrder(root->right);
}
//O(H)
bool search(Node* root,int key){
    if(root==NULL){
        return false;
    }

    if(root->key == key){
        return true;
    }

    if(key < root->key){
        return search(root->left,key);
    }
    return search(root->right,key);
}

//find min
Node* findMin(Node* root){
    while(root != NULL){
        root = root->left;
    }
    return root;
}

//BST Deletion 
Node* remove(Node* root,int key){ 
    if(root == NULL){
        return NULL;
    }
    else if(key < root->key){
        root->left = remove(root->left,key); 
    }
    else if(key > root->key){
        root->right = remove(root->right,key);
    }
    else{
        // current node is the key

        //node with no child
        if(root->left == NULL and root->right == NULL){
            delete root;
            root = NULL;
        }

        //node with one child
        else if(root->left == NULL){
            Node* temp = root;
            root = root -> right;
            delete temp;
        }
        else if(root->right == NULL){
            Node* temp = root;
            root = root -> left;
            delete temp;
        }

        //node with two child
        else{
            Node* temp = findMin(root->right);
            root->key = temp->key;
            remove(root->right,temp->key);
        }
    }
    return root;
}

//Challenge : Print all elements in BST which lie in range K1 and K2
void printInRange(Node* root,int k1,int k2){
    if(root == NULL){
        return;
    }
    // both side
    if(root->key >= k1 and root->key <= k2){
        printInRange(root->left,k1,k2);
        cout<<root->key<<" ";
        printInRange(root->right,k1,k2);
    }
    else if(root->key > k2){
        //left subtree
        printInRange(root->left,k1,k2);
    }
    else{
        //root->key <k1
        printInRange(root->right,k1,k2);
    }
}

int main(){
    Node* root = NULL;

    int arr[] = {5,7,2,9,6,1,13};

    for(int x : arr){
        root = insert(root,x);
    }

    //printInOrder(root);
    //cout<<endl;

    int key;
    //cin>>key;

    //cout<<search(root,key)<<endl;
    //remove(root,key);

    //printInOrder(root);

    printInRange(root,2,9);

    return 0;
}