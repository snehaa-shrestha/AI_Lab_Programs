#include <iostream>
#include <vector>
#include <unordered_map>

class NaiveBayes {
    std::unordered_map<int, int> classCounts;
    std::unordered_map<int, std::unordered_map<int, int>> featureCounts;
    int totalSamples = 0;

public:
    void train(const std::vector<std::vector<int>>& data, const std::vector<int>& labels) {
        for (size_t i = 0; i < data.size(); i++) {
            int label = labels[i];
            classCounts[label]++;
            totalSamples++;
            for (int feature : data[i]) {
                featureCounts[feature][label]++;
            }
        }
    }

    int predict(const std::vector<int>& sample) {
        std::unordered_map<int, double> probabilities;
        for (const auto& [label, count] : classCounts) {
            double prob = (double)count / totalSamples;
            for (int feature : sample) {
                prob *= (double)(featureCounts[feature][label] + 1) / (count + 2); // Laplace smoothing
            }
            probabilities[label] = prob;
        }
        return (probabilities[0] > probabilities[1]) ? 0 : 1;
    }
};

int main() {
    NaiveBayes nb;

    // Simple training data for two classes (0 and 1)
    std::vector<std::vector<int>> trainingData = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};
    std::vector<int> labels = {1, 0, 0, 1};

    nb.train(trainingData, labels);

    std::vector<int> testSample = {1, 1};
    int prediction = nb.predict(testSample);
    std::cout << "Prediction for sample {1, 1}: " << prediction << std::endl;

    return 0;
}
