//
// Created by Tommy on 5/5/2020.
//

#ifndef INC_20S_PA04_TOMMYGREIM_QUICKSELECT_H
#define INC_20S_PA04_TOMMYGREIM_QUICKSELECT_H

#include <iterator>
#include <algorithm>
#include <vector>

template <typename T>
class quickSelect {
private:
    quickSelect();
    unsigned int  partition(T& theList, unsigned int startIndex, unsigned int endIndex, unsigned int pivot);
    static typename T::iterator selectNthSmallest(T& theList, unsigned int startIndex, unsigned int endIndex, unsigned int n);
public:
    static typename T::iterator selectNthSmallest(T& theList, unsigned int n);
};

template <typename T>
typename T::iterator quickSelect<T>::selectNthSmallest(T& theList, unsigned int n){
    unsigned int endIndex = std::distance(theList.begin(), theList.end()) - 1;
    return selectNthSmallest(theList, 0, endIndex, n);
}

template<typename T>
typename T::iterator quickSelect<T>::selectNthSmallest(T& theList, unsigned int startIndex, unsigned int endIndex, unsigned int n) {
//    if(startIndex >= endIndex){
//        return theList.begin() + startIndex;
//    }

    unsigned int oldStartIndex = startIndex;
    unsigned int oldEndIndex = endIndex;

    typename T::iterator pivot;

    unsigned int pivotIndex = (startIndex + endIndex) / 2;

    pivot = theList.begin() + pivotIndex;

    while(startIndex <= endIndex){
        while(*(theList.begin() + startIndex) < *pivot){
            startIndex++;
        }
        while(*(theList.begin() + endIndex) > *pivot){
            endIndex--;
        }
        if(startIndex <= endIndex){
            std::iter_swap((theList.begin() + startIndex), (theList.begin() + endIndex));
            startIndex++;
            endIndex--;
        }
    }

    if(n == startIndex){
        return theList.begin() + startIndex - 1;
    }
    else if (n < startIndex){
        return selectNthSmallest(theList, oldStartIndex, startIndex - 1, n);
    }
    else{
        return selectNthSmallest(theList, startIndex + 1, oldEndIndex, n);
    }
//    unsigned int pivot = (startIndex + endIndex) / 2;
//    pivot = partition(theList, startIndex, endIndex, pivot);
}

template<typename T>
unsigned int quickSelect<T>::partition(T& theList, unsigned int startIndex, unsigned int endIndex, unsigned int pivot) {

}

#endif //INC_20S_PA04_TOMMYGREIM_QUICKSELECT_H
