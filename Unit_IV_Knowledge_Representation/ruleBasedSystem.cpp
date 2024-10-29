#include <iostream>
#include <string>

void diagnose(const std::string& symptom) {
    if (symptom == "cough") {
        std::cout << "Possible diagnosis: Cold or Flu.\n";
    } else if (symptom == "fever") {
        std::cout << "Possible diagnosis: Infection.\n";
    } else if (symptom == "headache") {
        std::cout << "Possible diagnosis: Migraine or Tension Headache.\n";
    } else {
        std::cout << "Symptom not recognized. Consult a doctor.\n";
    }
}

int main() {
    std::string symptom;
    std::cout << "Enter symptom (e.g., cough, fever, headache): ";
    std::cin >> symptom;
    diagnose(symptom);
    return 0;
}
