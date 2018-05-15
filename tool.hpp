#include <iostream>

template <typename T>
std::ostream& operator << (std::ostream& out, std::vector<T> vec) {
    out << "[";
    for (typename std::vector<T>::iterator ite(vec.begin()); ite != vec.end(); ite++) {
        out << *ite;
        if (vec.end() != ite + 1)
            out << ", ";
    }
    out << "]";
    return out;
}
