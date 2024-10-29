#include <iostream>
#include <vector>

class Perceptron {
    std::vector<double> weights;
    double bias;
    double learningRate;

public:
    Perceptron(double lr = 0.1) : weights(2, 0.0), bias(0.0), learningRate(lr) {}

    int predict(int x1, int x2) {
        double sum = x1 * weights[0] + x2 * weights[1] + bias;
        return sum >= 0 ? 1 : 0;
    }

    void train(const std::vector<std::vector<int>>& inputs, const std::vector<int>& outputs, int epochs) {
        for (int epoch = 0; epoch < epochs; ++epoch) {
            for (size_t i = 0; i < inputs.size(); i++) {
                int x1 = inputs[i][0];
                int x2 = inputs[i][1];
                int y = outputs[i];
                int pred = predict(x1, x2);
                int error = y - pred;

                weights[0] += learningRate * error * x1;
                weights[1] += learningRate * error * x2;
                bias += learningRate * error;
            }
        }
    }
};

int main() {
    // Data for AND gate
    std::vector<std::vector<int>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<int> andOutputs = {0, 0, 0, 1};
    std::vector<int> orOutputs = {0, 1, 1, 1};

    Perceptron perceptron;

    // Train for AND gate
    std::cout << "Training for AND gate:" << std::endl;
    perceptron.train(inputs, andOutputs, 10);
    for (const auto& input : inputs) {
        std::cout << "Input: {" << input[0] << ", " << input[1] << "} Output: " << perceptron.predict(input[0], input[1]) << std::endl;
    }

    // Train for OR gate
    std::cout << "\nTraining for OR gate:" << std::endl;
    perceptron.train(inputs, orOutputs, 10);
    for (const auto& input : inputs) {
        std::cout << "Input: {" << input[0] << ", " << input[1] << "} Output: " << perceptron.predict(input[0], input[1]) << std::endl;
    }

    return 0;
}
