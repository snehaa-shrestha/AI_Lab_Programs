#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

class SemanticNetwork {
    std::unordered_map<std::string, std::vector<std::string>> relations;

public:
    void addRelation(const std::string& person, const std::string& relation, const std::string& relatedPerson) {
        relations[person].push_back(relation + " of " + relatedPerson);
    }

    void displayRelations(const std::string& person) const {
        if (relations.find(person) != relations.end()) {
            std::cout << person << " relations:\n";
            for (const auto& relation : relations.at(person)) {
                std::cout << "- " << relation << "\n";
            }
        } else {
            std::cout << "No relations found for " << person << ".\n";
        }
    }
};

int main() {
    SemanticNetwork familyNetwork;

    familyNetwork.addRelation("Alice", "Mother", "Bob");
    familyNetwork.addRelation("Bob", "Brother", "Charlie");
    familyNetwork.addRelation("Alice", "Aunt", "David");

    familyNetwork.displayRelations("Alice");
    familyNetwork.displayRelations("Bob");

    return 0;
}
