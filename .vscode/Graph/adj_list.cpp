#include<iostream>
#include<list>
#include<queue>
#include<vector>
#include<climits>
#include<set>
using namespace std;


class Graph{
    list<int> *l;
    int V;

public:

    Graph(int v){
        V = v;
        l = new list<int> [V];
    }

    void addEdge(int i,int j,bool undir = true){
        l[i].push_back(j);
        if(undir){
            l[j].push_back(i);
        }
    }

    void printAdjList(){
        //Iterate over all the rows
        for(int i=0;i<V;i++){
            cout<<i<<"-->";
            //every element of the ith linked list
            for(auto node : l[i]){
                cout<<node<<",";
            }
            cout<<endl;
        }
    }

    void BFS(int source){
        queue<int> q;
        bool *visited = new bool [V]{0};

        q.push(source);
        visited[source] = true;

        while(!q.empty()){
            //do some work for every node
            int f = q.front();
            cout<<f<<endl;
            q.pop();
            
            //push the nbrs of current node in q if they are not already visited
            for(auto nbr : l[f]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr] = true;
                }
            }
        }
    }

    void dfsHelper(int node,bool *visited){
        visited[node] = true;
        cout<<node<<",";

        //make a dfs call on all the unvisited nbr of node
        for(int nbr : l[node]){
            if(!visited[nbr]){
                dfsHelper(nbr,visited);
            }
        }
        return;
    }

    void DFS(int source){
        bool *visited = new bool[V]{0};
        dfsHelper(source,visited);
    }
    
    // dijkstras algo for sssp
    /*int dijkstras(int source,int dest){
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;

        dist[source] = 0;
        //initialize the set by inserting source node
        s.insert({dist[source],source});

        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            int distTilnow = it->first;
            s.erase(it);  //pop
            
            //iterate over the nbr of node
            for(auto nbrpair : l[node]){
                int nbr = nbrpair.second;
                int currentEdge = nbrpair.first;
                
                if(distTilnow + currentEdge < dist[nbr]){
                    //remove the pair if it already exists in set
                    auto f = s.find({dist[nbr],nbr});
                    if(f != s.end()){
                        s.erase(f);
                    }
                    //insert the updated pair in the set
                    dist[nbr] = distTilnow + currentEdge;
                }

            }
        }
        //distance from node
        for(int i=0;i<V;i++){
            cout<<"Node "<<i<<"distance "<<dist[i]<<endl;
        }
        return dist[dest];
    }*/
};

int main(){
    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(0,4);
    g.addEdge(1,2);
    g.addEdge(4,3);
    g.addEdge(4,5);
    g.addEdge(5,3);
    g.addEdge(3,2);

    //g.printAdjList();

    //g.BFS(0);
    //g.DFS(0);
    
    //g.dijkstras(0,4);
    return 0;
}