#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

class Graph {
public:
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;
    std::unordered_map<int, int> heuristic;

    void addEdge(int u, int v, int cost) {
        adjList[u].push_back({v, cost});
    }

    void setHeuristic(int node, int hValue) {
        heuristic[node] = hValue;
    }

    void AStarSearch(int start, int goal) {
        std::unordered_map<int, int> costSoFar;
        auto compare = [this, &costSoFar](int lhs, int rhs) { return costSoFar[lhs] + heuristic[lhs] > costSoFar[rhs] + heuristic[rhs]; };
        std::priority_queue<int, std::vector<int>, decltype(compare)> pq(compare);

        pq.push(start);
        costSoFar[start] = 0;

        while (!pq.empty()) {
            int node = pq.top();
            pq.pop();

            if (node == goal) {
                std::cout << "Goal reached!" << std::endl;
                return;
            }

            for (auto [neighbor, cost] : adjList[node]) {
                int newCost = costSoFar[node] + cost;
                if (costSoFar.find(neighbor) == costSoFar.end() || newCost < costSoFar[neighbor]) {
                    costSoFar[neighbor] = newCost;
                    pq.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 4);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 5, 2);

    g.setHeuristic(1, 3);
    g.setHeuristic(2, 2);
    g.setHeuristic(3, 4);
    g.setHeuristic(4, 1);
    g.setHeuristic(5, 0);

    std::cout << "A* Search from 1 to 5: ";
    g.AStarSearch(1, 5);

    return 0;
}
