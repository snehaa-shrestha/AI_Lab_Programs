#include <iostream>
#include <vector>

enum Action { MOVE_UP, MOVE_DOWN, MOVE_LEFT, MOVE_RIGHT };

struct Environment {
    std::vector<std::vector<int>> grid;
    int agent_x, agent_y;

    Environment(int width, int height) : grid(height, std::vector<int>(width, 0)), agent_x(0), agent_y(0) {
        grid[1][1] = 1; // obstacle at (1,1)
    }

    bool isObstacle(int x, int y) {
        return grid[y][x] == 1;
    }

    void printGrid() {
        for (int y = 0; y < grid.size(); y++) {
            for (int x = 0; x < grid[0].size(); x++) {
                if (x == agent_x && y == agent_y) {
                    std::cout << "A ";
                } else if (grid[y][x] == 1) {
                    std::cout << "# ";
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }
};

class ReflexAgent {
public:
    void act(Environment &env) {
        if (!env.isObstacle(env.agent_x, env.agent_y + 1)) {
            env.agent_y++;
        } else if (!env.isObstacle(env.agent_x + 1, env.agent_y)) {
            env.agent_x++;
        } else if (!env.isObstacle(env.agent_x, env.agent_y - 1)) {
            env.agent_y--;
        } else if (!env.isObstacle(env.agent_x - 1, env.agent_y)) {
            env.agent_x--;
        }
    }
};

int main() {
    Environment env(5, 5);
    ReflexAgent agent;

    for (int i = 0; i < 10; ++i) {
        env.printGrid();
        agent.act(env);
    }

    return 0;
}
