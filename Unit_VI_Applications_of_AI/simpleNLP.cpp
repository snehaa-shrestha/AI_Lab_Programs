#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>

class SimpleNLP {
public:
    void countWords(const std::string& text) {
        std::unordered_map<std::string, int> wordCount;
        std::string word;

        std::istringstream stream(text);
        while (stream >> word) {
            // Convert to lowercase for uniformity
            for (auto& c : word) c = tolower(c);
            wordCount[word]++;
        }

        // Display the word counts
        std::cout << "Word Frequency:\n";
        for (const auto& [word, count] : wordCount) {
            std::cout << word << ": " << count << "\n";
        }
    }
};

int main() {
    SimpleNLP nlp;
    std::string text = "Hello world! Hello everyone. Welcome to the world of C++ programming.";

    nlp.countWords(text);

    return 0;
}
