#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void details() {
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

const int MAX_VERTICES = 20;
const int MAX_EDGES = 50;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    Edge edges[MAX_EDGES];
};

int findParent(vector<int>& parent, int i) {
    if (parent[i] == -1)
        return i;
    return findParent(parent, parent[i]);
}

void unionSets(vector<int>& parent, int x, int y) {
    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);
    parent[xroot] = yroot;
}

bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

void kruskalMST(Graph* graph) {
    int V = graph->V;
    Edge result[MAX_VERTICES];
    int e = 0;
    int i = 0;

    sort(graph->edges, graph->edges + graph->E, compareEdges);

    vector<int> parent(V, -1);

    while (e < V - 1 && i < graph->E) {
        Edge next_edge = graph->edges[i++];
        int x = findParent(parent, next_edge.src);
        int y = findParent(parent, next_edge.dest);
        if (x != y) {
            result[e++] = next_edge;
            unionSets(parent, x, y);
        }
    }

    cout << "Edge\tWeight" << endl;
    for (i = 0; i < e; i++) {
        cout << result[i].src << " - " << result[i].dest << "\t" << result[i].weight << endl;
    }
}

int main() {
    Graph graph;

    details();

    cout << "Enter the number of vertices: ";
    cin >> graph.V;

    cout << "Enter the number of edges: ";
    cin >> graph.E;

    cout << "Enter edge details (src, dest, weight):" << endl;
    for (int i = 0; i < graph.E; i++) {
        cin >> graph.edges[i].src >> graph.edges[i].dest >> graph.edges[i].weight;
    }

    kruskalMST(&graph);

    return 0;
}
