#include <iostream>
#include <string>

class Person {
public:
    std::string name;
    int age;
    std::string occupation;

    Person(const std::string& n, int a, const std::string& o) : name(n), age(a), occupation(o) {}

    void display() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Occupation: " << occupation << "\n";
    }
};

int main() {
    Person person1("Sneha", 20, "Under Graduate");
    person1.display();

    return 0;
}
