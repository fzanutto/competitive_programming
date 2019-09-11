#include <bits/stdc++.h>

#define NINF INT_MIN

using namespace std;

// Graph is represented using adjacency list. Every
// node of adjacency list contains vertex number of
// the vertex to which edge connects. It also
// contains weight of the edge
class AdjListNode {
    int v;
    int weight;

public:
    AdjListNode(int _v, int _w) {
        v = _v;
        weight = _w;
    }
    int getV() {
        return v;
    }
    int getWeight() {
        return weight;
    }
};

class Graph {
    int V;
    list<AdjListNode>* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new list<AdjListNode>[V];
    }

    void addEdge(int u, int v, int weight){
        AdjListNode node(v, weight);
        adj[u].push_back(node);
    }

    void topologicalSort(int v, bool visited[], stack<int> &Stack) {
        visited[v] = true;

        list<AdjListNode>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); ++i) {
            AdjListNode node = *i;
            if (!visited[node.getV()])
                topologicalSort(node.getV(), visited, Stack);
        }
        Stack.push(v);
    }

    int longestPath(int sources[]){
        stack<int> Stack;
        int dist[V] = {};

        bool* visited = new bool[V];
        for (int i = 0; i < V; i++)
            visited[i] = false;

        // Toposort
        for (int i = 0; i < V; i++)
            if (visited[i] == false)
                topologicalSort(i, visited, Stack);

        // Initialize distances to all vertices as infinite and
        // distance to sources as 0
        for (int i = 0; i < V; i++){
            if(!sources[i]){
                dist[i] = NINF;
            }
        }

        // Process vertices in topological order
        while (Stack.empty() == false) {
            int u = Stack.top();
            Stack.pop();

            list<AdjListNode>::iterator i;
            if (dist[u] != NINF) {
                for (i = adj[u].begin(); i != adj[u].end(); ++i)
                    dist[i->getV()] = max(dist[u] + i->getWeight(), dist[i->getV()]);
            }
        }

        return *(max_element(dist, dist+V));

    }
};

int main() {

    int n,m;

    cin >> n >> m;

    Graph g(n+1);
    int sources[n+1];

    for(int i=1; i<=n; i++){
        sources[i] = 1;
    }

    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g.addEdge(a,b,c);
        sources[b] = 0;
    }

    cout << g.longestPath(sources) << endl;

    return 0;
}
