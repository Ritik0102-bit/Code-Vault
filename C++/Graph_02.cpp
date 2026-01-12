// Detect Cycle In Undirected Graph Using DFS

#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Graph{
    int v;
    list<int> *l;

    public:
    Graph(int v){
        this->v=v;
        l = new list<int> [v];
    }

    void Add_edge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool is_Cycle_DFS_Helper(int src,int parent,vector<bool> &visited){
        visited[src]=true;

        for(int i:l[src]){
            if(!visited[i]){
                if(is_Cycle_DFS_Helper(i,src,visited)){
                    return true;
                }
            }
            else if(i != parent){
                return true;
            }
        }

        return false;
    } 

    bool is_Cycle_DFS(){
        vector<bool> visited(v,false);

        for(int i=0;i<v;i++){
            if(!visited[i]){
                if(is_Cycle_DFS_Helper(i,-1,visited)){
                    return true;
                }
            }
        }

        return false;
    }
};

int main(){
    Graph g(5);
    
    g.Add_edge(0,1);
    g.Add_edge(0,2);
    g.Add_edge(0,3);
    g.Add_edge(1,2);
    g.Add_edge(3,4);
    
    cout << g.is_Cycle_DFS();

    return 0;
}