#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

class Graph {
public:
    std::unordered_map<int, std::vector<int>> adjList;

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    void DFS(int start) {
        std::unordered_map<int, bool> visited;
        std::stack<int> s;
        s.push(start);

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                std::cout << node << " ";
                visited[node] = true;
            }

            for (int neighbor : adjList[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
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

    std::cout << "DFS starting from node 1: ";
    g.DFS(1);
    std::cout << std::endl;

    return 0;
}
