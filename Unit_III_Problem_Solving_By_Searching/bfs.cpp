#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

class Graph {
public:
    std::unordered_map<int, std::vector<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void BFS(int start) {
        std::unordered_map<int, bool> visited;
        std::queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            std::cout << node << " ";

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(3, 5);

    std::cout << "BFS starting from node 1: ";
    g.BFS(1);
    std::cout << std::endl;

    return 0;
}
