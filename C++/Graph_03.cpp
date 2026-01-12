// Detect Cycle In Undirected Graph Using BFS

#include<iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Graph {
    int v;
    list<int> *l;

public:
    Graph(int v) {
        this->v = v;
        l = new list<int>[v];
    }

    void Add_edge(int u, int v) {
        l[u].push_back(v);
        l[v].push_back(u);
    }

    bool is_Cycle_BFS_Helper(int src, vector<bool> &visited) {
        // Queue stores pairs of {current_node, parent_node}
        queue<pair<int, int>> q;
        
        visited[src] = true;
        q.push({src, -1});

        while (!q.empty()) {
            int curr = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (int neighbor : l[curr]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push({neighbor, curr});
                } 
                // If visited and not the parent, we found a cycle
                else if (neighbor != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool is_Cycle_BFS() {
        vector<bool> visited(v, false);

        // Loop handles disconnected components
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                if (is_Cycle_BFS_Helper(i, visited)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    Graph g(5);
    g.Add_edge(0, 1);
    // g.Add_edge(0, 2);
    g.Add_edge(0, 3);
    g.Add_edge(1, 2);
    g.Add_edge(3, 4);

    if (g.is_Cycle_BFS()) {
        cout << "Cycle detected using BFS" << endl;
    } else {
        cout << "No cycle detected" << endl;
    }

    return 0;
}