#include<iostream>
#include<queue>
using namespace std;


//i/p = 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        data = d;
        left = right = NULL;
    }
};

   //Preorder build of tree root,left,right tree
    Node* buildTree(){
        int d;
        cin>>d;

        if(d==-1){
            return NULL;
        }

        Node* n = new Node(d);
        n->left = buildTree();
        n->right = buildTree();
        return n;
    }

    //Preorder print
    void PreorderPrint(Node* root){
        if(root == NULL){
            return;
        }

        cout<<root->data<<" ",
        PreorderPrint(root->left);
        PreorderPrint(root->right);
    }

    //Inorder print
    void inorderPrint(Node* root){
        if(root == NULL){
            return;
        }

        inorderPrint(root->left);
        cout<<root->data<<" ";
        inorderPrint(root->right);
    }

    //post ORder print
    void postOrderPrint(Node* root){
        if(root ==NULL){
            return;
        }

        postOrderPrint(root->left);
        postOrderPrint(root->right);
        cout<<root->data<<" ";
    }

    // level order traversals
    void levelOrderPrint(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* temp = q.front();
            if(temp == NULL){
                cout<<endl;
                q.pop();
                //insert new NULL
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                q.pop();
                cout<<temp->data<<" ";
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
            }
        }
        return;
    }

    Node* levelOrderBuild(){
        queue<Node*> q;

        int d;
        cin>>d;

        Node* root = new Node(d);
        q.push(root);

        while(!q.empty()){
            Node* current = q.front();
            q.pop();

            int c1,c2;
            cin>>c1>>c2;

            if(c1!=-1){
                current->left = new Node(c1);
                q.push(current->left);
            }
            if(c2!=-1){
                current->right = new Node(c2);
                q.push(current->right);
            }
        }
        return root;
    }

    //height of treee
    int height(Node* root){
        if(root == NULL){
            return 0;
        }

        int h1 = height(root->left);
        int h2 = height(root->right);

        return 1+max(h1,h2);
    }

    //Diameter of tree
    int diameter(Node* root){
        //base case
        if(root == NULL){
            return 0;
        }

        //rec case
        int D1 = height(root->left) + height(root->right);  //(diameter passing grom root node)
        int D2 = diameter(root->left);
        int D3 = diameter(root->right);

        int D = max(D1,max(D2,D3));
        return D;
    }

    // Print all root to leaf paths
    void printroot2leafPath(Node* root,vector<int> &path){
        if(root == NULL){
            return;
        }

        if(root->left == NULL and root->right == NULL){
            //leaf node
            for(int x : path){
                cout<<x<<"->";
            }
            cout<<root->data<<"->";
            cout<<endl;
            return;
        }

        //rec case
        path.push_back(root->data);
        printroot2leafPath(root->left,path);
        printroot2leafPath(root->right,path);
        //backtracking
        path.pop_back(); 

        return;
    }

int main(){
    Node* root = buildTree();
   /* PreorderPrint(root);
    cout<<endl;
    inorderPrint(root);
    cout<<endl;
    postOrderPrint(root);*/
    
    //Node* root = levelOrderBuild();
    //levelOrderPrint(root);

    //cout<<"Height is : "<<height(root)<<endl;
    //cout<<"Diameter is : "<<diameter(root)<<endl;
    
    vector<int> path;
    printroot2leafPath(root,path);

    return 0;
}