#include <iostream>
#include <queue>
#include <unordered_set>

struct JugState {
    int jug1, jug2;
    JugState(int x, int y) : jug1(x), jug2(y) {}
};

// Custom hash function for pairs to use in unordered_set
struct HashPair {
    size_t operator()(const std::pair<int, int>& p) const {
        return std::hash<int>()(p.first) ^ std::hash<int>()(p.second);
    }
};

bool solveWaterJug(int jug1Capacity, int jug2Capacity, int target) {
    std::queue<JugState> q;
    std::unordered_set<std::pair<int, int>, HashPair> visited;

    q.push(JugState(0, 0));
    visited.insert({0, 0});

    while (!q.empty()) {
        JugState current = q.front();
        q.pop();

        // Check if we have reached the target amount in either jug
        if (current.jug1 == target || current.jug2 == target) {
            std::cout << "Solution found: Jug1: " << current.jug1 << ", Jug2: " << current.jug2 << std::endl;
            return true;
        }

        // Possible moves
        JugState states[] = {
            JugState(jug1Capacity, current.jug2), // Fill jug1
            JugState(current.jug1, jug2Capacity), // Fill jug2
            JugState(0, current.jug2),            // Empty jug1
            JugState(current.jug1, 0),            // Empty jug2
            // Pour water from jug2 to jug1
            JugState(std::min(jug1Capacity, current.jug1 + current.jug2), current.jug2 - (std::min(jug1Capacity - current.jug1, current.jug2))),
            // Pour water from jug1 to jug2
            JugState(current.jug1 - (std::min(jug2Capacity - current.jug2, current.jug1)), std::min(jug2Capacity, current.jug1 + current.jug2))
        };

        for (JugState next : states) {
            std::pair<int, int> statePair = {next.jug1, next.jug2};

            // Only visit a state if it hasn't been visited yet
            if (visited.find(statePair) == visited.end()) {
                q.push(next);
                visited.insert(statePair);
                std::cout << "Move to state: Jug1: " << next.jug1 << ", Jug2: " << next.jug2 << std::endl;
            }
        }
    }
    std::cout << "No solution found." << std::endl;
    return false;
}

int main() {
    int jug1Capacity = 4, jug2Capacity = 3, target = 2;
    solveWaterJug(jug1Capacity, jug2Capacity, target);
    return 0;
}
