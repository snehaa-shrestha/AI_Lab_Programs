#include <iostream>
#include <vector>

int minimax(int depth, bool isMaximizingPlayer) {
    if (depth == 0) return 0;

    if (isMaximizingPlayer) {
        int best = -1000;
        best = std::max(best, minimax(depth - 1, false));
        return best;
    } else {
        int best = 1000;
        best = std::min(best, minimax(depth - 1, true));
        return best;
    }
}

int main() {
    int result = minimax(3, true);
    std::cout << "MiniMax result: " << result << std::endl;
    return 0;
}
