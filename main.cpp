#include <iostream>
#include "trivialSelect.h"
#include "quickSelect.h"
#include <vector>
#include <chrono>
#include <random>

int main() {
    //Assigns the number of elements per test case
    const int NUM_ELEMENTS = 10000000;


    std::default_random_engine rng;
    //Set seed ensures the same numbers are generated every time
    rng.seed(100);


    std::vector<int> testCase1(NUM_ELEMENTS);// = {5,4,2343,351,126};
    //Inserts every number from 1 to num_elements into the vector
    for(int i = 1; i < NUM_ELEMENTS; i++){
        //testCase1.at(i) = distribution(rng);
        testCase1. at(i) = i;
    }

    //shuffle the contents of the vector
    std::shuffle(testCase1.begin(), testCase1.end(), rng);

    std::chrono::steady_clock::time_point preSelect, postSelect;
    std::chrono::duration<double> selectTime{};


    //The Non-Trivial QuickSelect Selection Algorithm
    std::vector<int> testCase1Q = testCase1;

    preSelect = std::chrono::steady_clock::now();
    int thirdSmallest = *quickSelect<std::vector<int>>::selectNthSmallest(testCase1Q, 19);
    postSelect = std::chrono::steady_clock::now();
    selectTime = postSelect - preSelect;

    std::cout << std::endl << thirdSmallest << std::endl;
    std::cout << "Time to find: " << selectTime.count() << " seconds." << std::endl;

    std::vector<int> testCase1T = testCase1;

    preSelect = std::chrono::steady_clock::now();
    thirdSmallest = *trivialSelect<std::vector<int>>::selectNthSmallest(testCase1T, 19);
    postSelect = std::chrono::steady_clock::now();
    selectTime = postSelect - preSelect;

    std::cout << std::endl << thirdSmallest << std::endl;
    std::cout << "Time to find: " << selectTime.count() << " seconds." << std::endl;

    return 0;
}
