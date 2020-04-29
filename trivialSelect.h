//
// Created by Tommy on 4/29/2020.
//

#ifndef INC_20S_PA04_TOMMYGREIM_TRIVIALSELECT_H
#define INC_20S_PA04_TOMMYGREIM_TRIVIALSELECT_H

#include <iterator>
#include <algorithm>
#include <vector>

template <typename T>
class trivialSelect {
private:
    trivialSelect();
public:
    static typename T::iterator selectNthSmallest(T theVect, unsigned int n);
};

template <typename T>
typename T::iterator trivialSelect<T>::selectNthSmallest(T inList, unsigned int n){
    std::sort(inList.begin(), inList.end());
    auto nthElem = inList.begin();
    while(n > 1){
        nthElem++;
        n--;
    }
    return nthElem;
}

#endif //INC_20S_PA04_TOMMYGREIM_TRIVIALSELECT_H
