#include<iostream>
#include<list>
#include<vector>
#include<climits>
#include<set>
using namespace std;

//Dijkshtras algo for weighted graph
class Graph{
    int V;
    list<pair<int,int>> *l;
    public:
    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>> [V];
    }

    void adddEdge(int u,int v,int wt,bool undir = true){
        l[u].push_back({wt,v});
        if(undir){
            l[v].push_back({wt,u});
        }
    }

    int Dikshtras(int source,int dest){
        vector<int> dist(V,INT_MAX);
        set<pair<int,int>> s;

        dist[source] = 0;
        s.insert({0,source});

        while(!s.empty()){
            auto it = s.begin();
            int distTilNow = it->first;
            int node = it->second;
            s.erase(it);//pop

            for(auto nbrPair : l[node]){
                int currentEdge = nbrPair.first;
                int nbr = nbrPair.second;

                if(distTilNow + currentEdge < dist[nbr]){
                    //if pair is already in set
                    auto f = s.find({dist[nbr],nbr});
                    if(f!=s.end()){
                        s.erase(f);
                    }

                    //update the dist & insert in set
                    dist[nbr] = distTilNow + currentEdge;
                    s.insert({dist[nbr],nbr});
                }
            }
        }
        for(int i=0;i<V;i++){
            cout<<"Node "<<i<<" dist ->"<<dist[i]<<endl;
        }

        return dist[dest];
    }
};

int main(){
    Graph g(5);
    g.adddEdge(0,1,1);
    g.adddEdge(1,2,1);
    g.adddEdge(0,2,4);
    g.adddEdge(0,3,7);
    g.adddEdge(3,2,2);
    g.adddEdge(3,4,3);

    g.Dikshtras(0,7);

    return 0;
}