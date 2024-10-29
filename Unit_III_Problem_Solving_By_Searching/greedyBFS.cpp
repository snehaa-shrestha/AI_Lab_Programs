#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>

class Graph {
public:
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;
    std::unordered_map<int, int> heuristic; // heuristic function h(n)

    void addEdge(int u, int v, int cost) {
        adjList[u].push_back({v, cost});
    }

    void setHeuristic(int node, int hValue) {
        heuristic[node] = hValue;
    }

    void GreedyBestFirstSearch(int start, int goal) {
        std::unordered_map<int, bool> visited;
        auto compare = [this](int lhs, int rhs) { return heuristic[lhs] > heuristic[rhs]; };
        std::priority_queue<int, std::vector<int>, decltype(compare)> pq(compare);

        pq.push(start);

        while (!pq.empty()) {
            int node = pq.top();
            pq.pop();

            if (visited[node]) continue;
            visited[node] = true;
            std::cout << node << " ";

            if (node == goal) {
                std::cout << "\nGoal reached!" << std::endl;
                return;
            }

            for (auto [neighbor, cost] : adjList[node]) {
                if (!visited[neighbor]) {
                    pq.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 5, 2);

    g.setHeuristic(1, 3);
    g.setHeuristic(2, 2);
    g.setHeuristic(3, 4);
    g.setHeuristic(4, 1);
    g.setHeuristic(5, 0);

    std::cout << "Greedy Best-First Search from 1 to 5: ";
    g.GreedyBestFirstSearch(1, 5);

    return 0;
}
