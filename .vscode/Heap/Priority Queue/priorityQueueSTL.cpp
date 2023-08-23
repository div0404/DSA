#include<iostream>
#include<queue>
using namespace std;

//custom comparator
class compare{
    public:
    bool operator()(int a,int b){
        return a<b;
    }
};

int main(){
    int arr[] = {10,15,20,7,9,13};
    int n = sizeof(arr)/sizeof(int);

    //priority_queue<int,vector<int>,greater<int>> heap;  //grater(inbuilt comparator)
    priority_queue< int,vector<int>,compare > heap;

    for(int x : arr){
        heap.push(x);
    }

    while(!heap.empty()){
        cout<<heap.top()<<endl;
        heap.pop();
    }

    return 0;
}