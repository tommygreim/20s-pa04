#include <iostream>
#include "trivialSelect.h"
#include <vector>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> test;// = {5,4,2343,351,126};
    test.push_back(5);
    test.push_back(4);
    test.push_back(2343);
    test.push_back(351);
    test.push_back(126);
    int thirdSmallest = *trivialSelect<std::vector<int>>::selectNthSmallest(test, 3);
    std::cout << thirdSmallest << std::endl;
    return 0;
}
