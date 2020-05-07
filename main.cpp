#include <iostream>
#include "trivialSelect.h"
#include "quickSelect.h"
#include <vector>
#include <chrono>
#include <random>
#include <fstream>
#include <string.h>

int main(int argc, char** argv) {
    //Assigns the number of elements per test case
    const int NUM_ELEMENTS = 10000;
    std::default_random_engine rng;

    //If the program is run with the 'random' argument, then the numbers will be randomly generated.
    if((argc == 2) && (strcmp(argv[1], "random") == 0)){
        unsigned int seed = std::chrono::steady_clock::now().time_since_epoch().count();
        rng.seed(seed);
    }
    else{
        //Set seed ensures the same numbers are generated every time
        rng.seed(1000);
    }
    std::uniform_int_distribution<int> dist(0, NUM_ELEMENTS);

    std::ofstream output("output.txt");

    output << "Number of Elements\tSelect Type\tTime to Select (s)" << std::endl;

    for(int i = NUM_ELEMENTS; i < 1000 * NUM_ELEMENTS; i *= 2) {

        std::vector<int> testCase1(i);// = {5,4,2343,351,126};
        //Inserts every number from 1 to i into the vector
        for (int j = 1; j < i; j++) {
            //testCase1.at(i) = distribution(rng);
            testCase1.at(j) = j;
        }

        for (int j = 0; j < 3; j++) {
            //Determines which element to find
            int nthElement = dist(rng);
            std::cout << "Test Case #" << j + 1 << ": Finding the " << nthElement << "th smallest element" << std::endl;

            //shuffle the contents of the vector
            std::shuffle(testCase1.begin(), testCase1.end(), rng);

            //Initialize timepoint and duration variables for data collection
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
            output << i << "\t" << "Trivial" << "\t" << selectTime.count() << std::endl;

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
            output << i << "\t" << "Quickselect" << "\t" << selectTime.count() << std::endl;

            std::cout << std::endl << std::endl;

        }
    }
    return 0;
}
