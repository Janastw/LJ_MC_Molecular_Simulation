#include <iostream>
#include <vector>

void append_element(std::vector<int>& vec) {
    vec.push_back(42);
    std::cout << "Inside function: ";
    for (int i : vec) std::cout << i << " ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> my_vector = {1, 2, 3};
    std::cout << "Before function call: ";
    for (int i : my_vector) std::cout << i << " ";
    std::cout << std::endl;

    append_element(my_vector);

    std::cout << "After function call: ";
    for (int i : my_vector) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}