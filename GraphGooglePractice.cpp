#include <iostream>
#include <queue>
#include <list>
#include <map>

using namespace std;

class Graph {
    private:
        map<int, bool> visited;
        map<int, list<int>> adjacency;
    public:
        void addEdge(int, int);
        void DFS(int);
        void BFS(int);
};

// Add nodeTwo to list of adjacent nodes of nodeOne
void Graph::addEdge(int nodeOne, int nodeTwo) {
    adjacency[nodeOne].push_back(nodeTwo);
}

void Graph::DFS(int root) {
    visited[root] = true;
    cout << root << ' ';

    for (auto iter = adjacency[root].begin(); iter != adjacency[root].end(); iter++) {
        if (visited[*iter] == false) {
            DFS(*iter);
        }
    }
}

void Graph::BFS(int root) {
    queue<int> queue;

    visited[root] = true;
    queue.push(root);

    cout << root << ' ';

    while (queue.empty() == false) {
        int node = queue.front();
        queue.pop();

        for (auto iter = adjacency[node].begin(); iter != adjacency[node].end(); iter++) {
            if (visited[*iter] == false) {
                visited[*iter] = true;
                queue.push(*iter);

                cout << *iter << ' ';
            }
        }
    }
}

int main() {
    Graph graph;
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    cout << "Depth-First Traversal: ";
    graph.DFS(2);

    //cout << "Breadth-First Traversal: ";
    //graph.BFS(2);

    return 0;
}