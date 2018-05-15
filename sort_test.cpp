#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "sort.hpp"
//#include "tool.hpp"
using namespace std;

std::ostream& operator << (std::ostream& out, std::vector<int> vec) {
    out << "[";
    for (std::vector<int>::iterator ite(vec.begin()); ite != vec.end(); ite++) {
        out << *ite;
        if (vec.end() != ite + 1)
            out << ", ";
    }
    out << "]";
    return out;
}

bool is_sorted(vector<int> &to_confirm) {
    for (int i = 1; i < to_confirm.size(); i++) {
        if (to_confirm[i] < to_confirm[i - 1]) {
            return false;
        }
    }
    return true;
}

struct SortFunc {
    void(*func)(vector<int>&);
    string name;
    SortFunc(const char *t_name, void(*t_func)(vector<int>&)): name(string(t_name)), func(t_func) {
       cout << "Added function " << this->name << endl;
    }
};

    
int main() {
    int length = 10;
    int l_range = 0;
    int r_range = 100;

    vector<SortFunc> func_vec;
    //func_vec.push_back(SortFunc("selection", selection));
    //func_vec.push_back(SortFunc("insertion", insertion));
    //func_vec.push_back(SortFunc("bubble", bubble));
    func_vec.push_back(SortFunc("shell", shell));

    srand(time(NULL));
    vector<int> to_sort;
    int range = r_range - l_range;
    for (int i = 0; i < length; i++) {
        to_sort.push_back(rand() % range + l_range);
    }
    cout << "Created vector with length "<< length << endl;
    cout << to_sort << endl;

    for (int i = 0; i < func_vec.size(); i++) {
        SortFunc *p = &func_vec[i];
        vector<int> vec(to_sort);
        double start_time = clock();
        p->func(vec);
        double time_cost = (clock() - start_time) / CLOCKS_PER_SEC;
        cout << p->name << " finished, " << time_cost << "sec passed. Result: " << (is_sorted(vec) ? "True" : "False") << endl;
    }
}
