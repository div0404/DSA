#include<iostream>
#include<vector>
using namespace std;

int main(){
    //vector<int> arr = {1,5,3,11,9};

    //Fill  Constructer
    vector<int> arr(10,5);

    vector<int> vector1(100,0);
    
    //removing last element
    arr.pop_back();

    //inserting element
    arr.insert(arr.begin()+2, 4);

    //erase 4th element
    arr.erase(arr.begin()+3);

    //erase first three element
    arr.erase(arr.begin(),arr.begin()+2);

    //adding elelment at the end
    arr.push_back(7);

    //output of vector
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }

    //size of vector
    //cout<<arr.size()<<endl;


    //capacity of vector
    //cout<<arr.capacity()<<endl;

    return 0;
}