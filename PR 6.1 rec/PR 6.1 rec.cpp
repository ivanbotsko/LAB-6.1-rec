#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

std::vector<int> generateArray(int size, int min, int max) {
    std::vector<int> array;
    for (int i = 0; i < size; i++) {
        array.push_back(rand() % (max - min + 1) + min);
    }
    return array;
}

struct CalculationResult {
    int count;
    int sum;
    std::vector<int> array;
};

CalculationResult calculateAndReplace(std::vector<int>& array, int i = 0, int count = 0, int sum = 0) {
    if (i < array.size()) {
        if (array[i] <= 0 || i % 2 == 0) {
            count++;
            sum += array[i];
            array[i] = 0;
        }
        return calculateAndReplace(array, i + 1, count, sum);
    }
    else {
        return { count, sum, array };
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    std::vector<int> array = generateArray(26, -40, 20);
    std::cout << "Original array: ";
    for (int i = 0; i < array.size(); i++) {
        std::cout << array[i];
        if (i != array.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    CalculationResult result = calculateAndReplace(array);
    std::cout << "Number of elements that satisfy the condition: " << result.count << std::endl;
    std::cout << "Sum of elements that satisfy the condition: " << result.sum << std::endl;

    std::cout << "Modified array: ";
    for (int i = 0; i < result.array.size(); i++) {
        std::cout << result.array[i];
        if (i != result.array.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
