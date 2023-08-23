#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define M 3
#define N 4

class Node{
    public :
    char s;
    unordered_map<char,Node*> children;
    bool isTerminal;
    string word;

    Node(char s){
        this->s = s;
        isTerminal = false;
        word = "";
    }
};

class Trie{
    public: 
    Node *root;
    Trie(){
        root = new Node('\0');
    }
    
    void addWord(string word){
        Node *temp = root;
        for(auto ch : word){
            if(temp->children.count(ch)==0){
                temp->children[ch] = new Node(ch);
            }
            temp = temp->children[ch];
        }
        temp->isTerminal = true;
        temp->word = word;
    }
};

//main algo 8 way dfs + guided trie
void dfs(char board[][N],Node* root,int i,int j,bool visited[][N],unordered_set<string> &output){
    //base case
    char ch = board[i][j];
    if(root->children.count(ch)==0){
        return;
    }

    //otherwise the ch is present
    visited[i][j] = true;
    root = root->children[ch];

    //at terminal node
    if(root->isTerminal){
        output.insert(root->word);
    }
    
    //make dfs call to all its neighbour
    int dx[] = {0,1,1,1,0,-1,-1,-1};
    int dy[] = {-1,-1,0,1,1,1,0,-1};

    for(int k=0;k<8;k++){

        int ni = i + dx[k];
        int nj = j + dy[k];
        //if it is in bounds and not visited
        if(ni>=0 and nj>=0 and ni<M and nj<N and !visited[ni][nj]){
            dfs(board,root,ni,nj,visited,output);
        }
    }   
    //while coming back (backtracking)
    visited[i][j] = false;
    return;
}
int main(){
    string words[] = {"SNAKE","FOR","QUEZ","SNACK","SNACKS","GO","TUNES","CAT"};

    char board[M][N] = {
        {'S','E','R','T'},
        {'U','N','K','S'},
        {'T','C','A','T'}
    };

    Trie t;
    for(auto word : words){
        t.addWord(word);
    }

    //container to store words
    unordered_set<string> output;


    //dfs call for every cell
    bool visited[M][N] = {0};

    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            dfs(board,t.root,i,j,visited,output);
        }
    }

    //print output
    for(auto name : output){
        cout<<name<<endl;
    }

    return 0;
}