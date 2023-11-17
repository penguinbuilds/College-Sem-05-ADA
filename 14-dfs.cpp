#include <iostream>
#include <vector>

using namespace std;

void details() {
    cout << endl;
    cout << "Name: Shaaswat K Jha" << endl;
    cout << "Enrollment No: A2305221208" << endl;
}

class Graph {
public:
    Graph(int vertices);
    void addEdge(int from, int to);
    void DFS(int startVertex);

private:
    int vertices;
    vector<vector<int>> adjacencyList;
    vector<bool> visited;
};

Graph::Graph(int vertices) {
    this->vertices = vertices;
    adjacencyList.resize(vertices);
    visited.resize(vertices, false);
}

void Graph::addEdge(int from, int to) {
    adjacencyList[from].push_back(to);
}

void Graph::DFS(int startVertex) {
    visited[startVertex] = true;
    cout << startVertex << " ";

    for (int adjacent : adjacencyList[startVertex]) {
        if (!visited[adjacent]) {
            DFS(adjacent);
        }
    }
}

int main() {
    details();
    
    int numVertices;
    cout << "Enter the number of vertices: ";
    cin >> numVertices;

    Graph g(numVertices);

    int numEdges;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    for (int i = 0; i < numEdges; i++) {
        int from, to;
        cout << "Enter edge " << i + 1 << " (from to): ";
        cin >> from >> to;
        g.addEdge(from, to);
    }

    int startVertex;
    cout << "Enter the starting vertex for DFS: ";
    cin >> startVertex;

    cout << "Depth-First Search (DFS) starting from vertex " << startVertex << ": ";
    g.DFS(startVertex);
    cout << endl;

    cout << endl;

    return 0;
}
