#include <iostream>
#include <string>

bool isBird(const std::string& animal) {
    return (animal == "sparrow" || animal == "eagle" || animal == "parrot");
}

bool canFly(const std::string& animal) {
    return (animal == "sparrow" || animal == "eagle" || animal == "parrot" || animal == "bat");
}

void checkAnimal(const std::string& animal) {
    if (isBird(animal)) {
        std::cout << animal << " is a bird.\n";
    } else {
        std::cout << animal << " is not a bird.\n";
    }

    if (canFly(animal)) {
        std::cout << animal << " can fly.\n";
    } else {
        std::cout << animal << " cannot fly.\n";
    }
}

int main() {
    std::string animal;
    std::cout << "Enter an animal (e.g., sparrow, bat): ";
    std::cin >> animal;
    checkAnimal(animal);
    return 0;
}
