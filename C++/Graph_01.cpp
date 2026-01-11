// Breadth First Search 
// Travel To Immediate Neighbors first

// Depth First Search 
// Keep Going To the 1st Unvisited Neighbor

// Time Complexity :- O(Vertices + Edges)

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

    void BFS_traversal(){
        queue<int> q;
        vector<bool> visited(v,false);
        
        q.push(0);
        visited[0]=true;
        
        while(q.size()>0){
            int src= q.front();
            q.pop();

            cout << src << " ";
            
            for(int dest:l[src]){
                if(!visited[dest]){
                    visited[dest]=true;
                    q.push(dest);
                }
            }
        }
    }

    
    void DFS_Traversal(int src,vector<bool> &visited){
        visited[src]=true;
        cout << src << " ";

        for(int dest:l[src]){
            if(!visited[dest]){
                DFS_Traversal(dest,visited);
            }
        }
    }
};

int main(){
    Graph g(5);
    
    g.Add_edge(0,1);
    g.Add_edge(1,2);
    g.Add_edge(1,3);
    g.Add_edge(2,4);
    
    g.BFS_traversal();
    cout <<endl;
    
    vector<bool> visited(5,false);
    g.DFS_Traversal(0,visited);

    return 0;
}