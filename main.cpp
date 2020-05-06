#include <iostream>
#include "trivialSelect.h"
#include "quickSelect.h"
#include <vector>
#include <chrono>
#include <random>

int main() {
    //Assigns the number of elements per test case
    const int NUM_ELEMENTS = 100;

    std::default_random_engine rng;
    //auto seed = std::chrono::steady_clock::now().time_since_epoch().count();
    rng.seed(100);
    std::uniform_int_distribution<int> distribution(1, NUM_ELEMENTS);
    std::cout << "Hello, World!" << std::endl;
    std::vector<int> testCase1(NUM_ELEMENTS);// = {5,4,2343,351,126};
    for(int i = 0; i < NUM_ELEMENTS; i++){
        //testCase1.at(i) = distribution(rng);
        testCase1. at(i) = i;
    }

    std::shuffle(testCase1.begin(), testCase1.end(), rng);

//    std::cout << "Test Case #1 [";
//    for(auto i = testCase1.begin(); i < testCase1.end(); i++){
//        std::cout << *i << ", ";
//    }
    std::cout << "]" << std:: endl;

    std::chrono::steady_clock::time_point preSelect, postSelect;
    std::chrono::duration<double> selectTime;

    preSelect = std::chrono::steady_clock::now();
    int thirdSmallest = *quickSelect<std::vector<int>>::selectNthSmallest(testCase1, 19);
    postSelect = std::chrono::steady_clock::now();
    selectTime = postSelect - preSelect;

    std::cout << std::endl << thirdSmallest << std::endl;
    std::cout << "Time to find: " << selectTime.count() << " seconds." << std::endl;

    preSelect = std::chrono::steady_clock::now();
    thirdSmallest = *trivialSelect<std::vector<int>>::selectNthSmallest(testCase1, 19);
    postSelect = std::chrono::steady_clock::now();
    selectTime = postSelect - preSelect;

    std::cout << std::endl << thirdSmallest << std::endl;
    std::cout << "Time to find: " << selectTime.count() << " seconds." << std::endl;

    return 0;
}
