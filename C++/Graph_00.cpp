#include<iostream>
#include<vector>
#include<list>

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

    void print_Adj_list(){
        for(int i=0;i<v;i++){
            cout << i << " : " ;
            for(int neighbor:l[i]){
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
};

int main(){
    Graph g(5);

    g.Add_edge(0,1);
    g.Add_edge(1,2);
    g.Add_edge(1,3);
    g.Add_edge(2,3);
    g.Add_edge(2,4);

    g.print_Adj_list();

    return 0;
}