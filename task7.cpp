#include <iostream>
#include <unordered_set>

using namespace std;

class Graph {
    int V;
    unordered_set<int>* adj;

public:
    Graph(int V) : V(V) {
        adj = new unordered_set<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].insert(v);
        adj[v].insert(u);
    }

    void DFSUtil(int v, bool* visited, unordered_set<int>& group) {
        visited[v] = true;
        group.insert(v);

        for (int u : adj[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited, group);
            }
        }
    }

    unordered_set<int>* getConnectedGroups() {
        bool* visited = new bool[V];
        for (int i = 0; i < V; ++i) {
            visited[i] = false;
        }

        unordered_set<int>* groups = new unordered_set<int>[V];

        for (int v = 0; v < V; ++v) {
            if (!visited[v]) {
                unordered_set<int> group;
                DFSUtil(v, visited, group);
                groups[v] = group;
            }
        }

        delete[] visited;
        return groups;
    }
};

int main() {
    int V = 6;
    Graph g(V);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(3, 4);
    g.addEdge(4, 5);

    unordered_set<int>* connectedGroups = g.getConnectedGroups();

    for (int v = 0; v < V; ++v) {
        if (connectedGroups[v].size() > 0) {
            cout << "Group: ";
            for (int user : connectedGroups[v]) {
                cout << user << " ";
            }
            cout << endl;
        }
    }

    delete[] connectedGroups;

    return 0;
}