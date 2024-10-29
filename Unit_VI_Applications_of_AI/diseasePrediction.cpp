#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class DiseaseExpertSystem {
    std::unordered_map<std::string, std::vector<std::string>> diseaseSymptoms;

public:
    DiseaseExpertSystem() {
        // Initialize with some diseases and their symptoms
        diseaseSymptoms["Flu"] = {"fever", "cough", "headache", "sore throat"};
        diseaseSymptoms["Cold"] = {"cough", "sore throat", "runny nose"};
        diseaseSymptoms["COVID-19"] = {"fever", "cough", "fatigue", "loss of taste"};
    }

    void predictDisease(const std::vector<std::string>& symptoms) {
        std::unordered_map<std::string, int> diseaseCount;

        for (const auto& symptom : symptoms) {
            for (const auto& [disease, diseaseSymptoms] : diseaseSymptoms) {
                if (std::find(diseaseSymptoms.begin(), diseaseSymptoms.end(), symptom) != diseaseSymptoms.end()) {
                    diseaseCount[disease]++;
                }
            }
        }

        // Find the disease with the highest count of matching symptoms
        std::string predictedDisease;
        int maxCount = 0;

        for (const auto& [disease, count] : diseaseCount) {
            if (count > maxCount) {
                maxCount = count;
                predictedDisease = disease;
            }
        }

        if (!predictedDisease.empty()) {
            std::cout << "Predicted Disease: " << predictedDisease << " based on symptoms.\n";
        } else {
            std::cout << "No matching disease found.\n";
        }
    }
};

int main() {
    DiseaseExpertSystem expertSystem;

    std::vector<std::string> symptoms = {"fever", "cough"};
    expertSystem.predictDisease(symptoms);

    return 0;
}
