#include <iostream>
#include "trivialSelect.h"
#include "quickSelect.h"
#include <vector>
#include <chrono>
#include <random>

int main() {
    //Assigns the number of elements per test case
    const int NUM_ELEMENTS = 10000000;

    //Set seed ensures the same numbers are generated every time
    std::default_random_engine rng(1000);
    std::uniform_int_distribution<int> dist(0, NUM_ELEMENTS);


    //      TEST CASE #1 (NUM ELEMENTS # Integers)

    std::vector<int> testCase1(NUM_ELEMENTS);// = {5,4,2343,351,126};
    //Inserts every number from 1 to num_elements into the vector
    for(int i = 1; i < NUM_ELEMENTS; i++){
        //testCase1.at(i) = distribution(rng);
        testCase1. at(i) = i;
    }

    //shuffle the contents of the vector
    for(int i = 0; i < 10; i++) {
        //Determines which element to find
        int nthElement = dist(rng);
        std::cout << "Test Case #" << i + 1 << ": Finding the " << nthElement << "th smallest element"<< std::endl;

        std::shuffle(testCase1.begin(), testCase1.end(), rng);

        std::chrono::steady_clock::time_point preSelect, postSelect;
        std::chrono::duration<double> selectTime{};

        //The Trivial Selection Algorithm
        std::vector<int> testCase1T = testCase1;

        preSelect = std::chrono::steady_clock::now();
        int foundSmallest = *trivialSelect<std::vector<int>>::selectNthSmallest(testCase1T, nthElement);
        postSelect = std::chrono::steady_clock::now();
        selectTime = postSelect - preSelect;

        std::cout << "\t==Trivial Implementation==" << std::endl;
        std::cout << "\tFound: " << foundSmallest << std::endl;
        std::cout << "\tTime to find: " << selectTime.count() << " seconds." << std::endl;

        std::cout << std::endl;

        //The Non-Trivial QuickSelect Selection Algorithm
        std::vector<int> testCase1Q = testCase1;

        preSelect = std::chrono::steady_clock::now();
        foundSmallest = *quickSelect<std::vector<int>>::selectNthSmallest(testCase1Q, nthElement);
        postSelect = std::chrono::steady_clock::now();
        selectTime = postSelect - preSelect;

        std::cout << "\t==Non-Trivial Implementation==" << std::endl;
        std::cout << "\tFound: " << foundSmallest << std::endl;
        std::cout << "\tTime to find: " << selectTime.count() << " seconds." << std::endl;

        std::cout << std::endl << std::endl;

    }
    return 0;
}
