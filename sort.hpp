#ifndef SORTING_H
#define SORTING_H

#include <ctime>
#include <cstdlib>

struct Sort {
    Vector<int> original;
    Vector<int> sorted;

    int size;
    double timeCost;
    Vector<int> (*func)(Vector<int>);

    void doit();
};

#endif
