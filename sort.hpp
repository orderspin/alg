#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <string>
#include "tool.hpp"

void exchange(std::vector<int> &input, int i, int j);

void selection(std::vector<int> &to_sort);
void insertion(std::vector<int> &to_sort);
void shell(std::vector<int> &to_sort);
void bubble(std::vector<int> &to_sort);
void merge(std::vector<int> &to_sort);

void exchange(std::vector<int> &input, int i, int j) {
    if (i != j) {
        int tmp = input[i];
        input[i] = input[j];
        input[j] = tmp;
    }
}

void selection(std::vector<int> &to_sort) {
    int N = to_sort.size();
    for (int i = 0; i < N; i++) {
        int min = i;
        for (int j = i + 1; j < N; j++) {
            if (to_sort[j] < to_sort[min]) {
                min = j;
            }
        }
        exchange(to_sort, min, i);
    }
}

void insertion(std::vector<int> &to_sort) {
    int N = to_sort.size();
    for (int i = 1; i < N; i++) {
        for (int j = i; j > 0 && to_sort[j] < to_sort[j - 1]; j--) {
            exchange(to_sort, j, j - 1);
        }
    }
}

void shell(std::vector<int> &to_sort) {
    int N = to_sort.size();
    int h = 1;
    while (h < N / 3) {
        h = h * 3 + 1;
    }
    while (h > 0) {
        for (int i = h; i < N; i++) {
            for (int j = i; j >= h && to_sort[j] < to_sort[j - h]; j -= h) {
                exchange(to_sort, j, j - h);
            }
            
        }
        h /= 3;
    }
}

void bubble(std::vector<int> &to_sort) {
    int N = to_sort.size();
    for (int i = N; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            if (to_sort[j] < to_sort[j - 1]) {
                exchange(to_sort, j, j - 1);
            }
        }
    }
}

void merge(std::vector<int> &to_sort) {

}

#endif
