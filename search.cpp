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
        std::cout << "compare " << compare(to_search, search_vec[mid]) <<" mid" << mid << std::endl;
    }
    return -1;
}

#endif

int f(int &a, int &b) {
    return a-b;
}

int main() {
    vector<int> a = {1,2,3,4,5,6,7,8};
    int tf = 5;
    cout << "!" << binary_search<int>(a, tf, f);

}
