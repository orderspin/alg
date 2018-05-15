#include <iostream>
#include <vector>
#include <cstdlib>
#include "sort.hpp"
using namespace std;

void test() {
    cout << "GG";
    if (1) cout << "GE";
}

int main() {
    cout << "BEGIN" << endl;
    double startTime = clock();
    test();
    double timeCost = (clock() - startTime) / CLOCKS_PER_SEC;
    cout << "FINISHED " << timeCost << "sec passed.";
}
