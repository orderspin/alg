#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <vector>
#include "tool.hpp"
using namespace std;

template<typename T>
int binary_search(std::vector<T> &search_vec, T &to_search, int(*compare)(T&, T&)) {
    int left = 0, right = search_vec.size();
    while (left <= right) {
        int mid = (left + right) / 2;
        if (compare(to_search, search_vec[mid]) < 0) {
            right = mid - 1;
        } else if (compare(to_search, search_vec[mid]) > 0) {
            left = mid + 1;
        } else {
            return mid;
        }
    }
    return -1;
}

#endif

