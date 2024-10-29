#include <iostream>
#include <cmath>
#include <vector>

class SimpleNeuralNetwork {
    double weights1[2][2]; // Weights between input and hidden layer
    double weights2[2];    // Weights between hidden layer and output
    double learningRate;

public:
    SimpleNeuralNetwork(double lr = 0.5) : learningRate(lr) {
        weights1[0][0] = 0.5; weights1[0][1] = -0.5;
        weights1[1][0] = -0.5; weights1[1][1] = 0.5;
        weights2[0] = 0.5; weights2[1] = 0.5;
    }

    double sigmoid(double x) { return 1.0 / (1.0 + exp(-x)); }
    double sigmoidDerivative(double x) { return x * (1.0 - x); }

    double train(const std::vector<int>& input, int target) {
        // Forward Pass
        double hidden[2];
        for (int i = 0; i < 2; i++) {
            hidden[i] = sigmoid(input[0] * weights1[0][i] + input[1] * weights1[1][i]);
        }
        double output = sigmoid(hidden[0] * weights2[0] + hidden[1] * weights2[1]);

        // Error Calculation
        double error = target - output;

        // Backpropagation
        double dOutput = error * sigmoidDerivative(output);
        for (int i = 0; i < 2; i++) {
            double dHidden = dOutput * weights2[i] * sigmoidDerivative(hidden[i]);
            weights2[i] += learningRate * dOutput * hidden[i];
            weights1[0][i] += learningRate * dHidden * input[0];
            weights1[1][i] += learningRate * dHidden * input[1];
        }
        return output;
    }
};

int main() {
    SimpleNeuralNetwork nn;

    std::vector<std::vector<int>> inputs = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    std::vector<int> outputs = {0, 1, 1, 0}; // Target outputs for XOR

    // Train the network
    for (int epoch = 0; epoch < 1000; epoch++) {
        for (size_t i = 0; i < inputs.size(); i++) {
            nn.train(inputs[i], outputs[i]);
        }
    }

    // Test the network
    std::cout << "Testing Neural Network on XOR problem:\n";
    for (const auto& input : inputs) {
        double result = nn.train(input, -1);  // -1 for testing only
        std::cout << "Input: {" << input[0] << ", " << input[1] << "} Output: " << (result > 0.5 ? 1 : 0) << std::endl;
    }

    return 0;
}
