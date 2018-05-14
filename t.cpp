#include <iostream>
#include "Vector.hpp"
using namespace std;

int main() {
    Vector<int> vec(11, 12);
    Vector<int> k;
    vec = vec;
    k = vec;
    cout << "FINISHED" << endl;
    cout << vec.size;
}
