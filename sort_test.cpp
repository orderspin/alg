#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>
#include "sort.hpp"
#include "search.hpp"
//#include "tool.hpp"
using namespace std;

bool is_sorted(vector<int> &to_confirm) {
    for (int i = 1; i < to_confirm.size(); i++) {
        if (to_confirm[i] < to_confirm[i - 1]) {
            return false;
        }
    }
    return true;
}

vector<int> random_vec(int length, int left, int right) {
    srand(time(NULL));
    vector<int> res;
    int range = right - left;
    for (int i = 0; i < length; i++) {
        res.push_back(rand() % range + left);
    }
    return res;
}

struct SortFunc {
    void(*func)(vector<int>&);
    string name;
    SortFunc(const char *t_name, void(*t_func)(vector<int>&)):
            name(string(t_name)),
            func(t_func) {
        cout << "Added function " << this->name << endl;
    }
};

int main() {
    int length = 10;
    int left = 0;
    int right = 100;
    bool if_print_vec = false;

    vector<SortFunc> func_vec;
    func_vec.push_back(SortFunc("selection", selection));
    func_vec.push_back(SortFunc("insertion", insertion));
    func_vec.push_back(SortFunc("bubble", bubble));
    func_vec.push_back(SortFunc("shell", shell));

    sleep(1000);
    vector<int> to_sort = random_vec(length, left, right);
    cout << "Created vector with length "<< length << endl;
    if (if_print_vec) {
        cout << to_sort << endl;
    }

    for (int i = 0; i < func_vec.size(); i++) {
        SortFunc *p = &func_vec[i];
        vector<int> vec(to_sort);
        double start_time = clock();
        p->func(vec);
        double time_cost = (clock() - start_time) / CLOCKS_PER_SEC;
        cout << p->name << " finished, " << time_cost << "sec passed. Result: " << (is_sorted(vec) ? "True" : "False") << endl;
        if (if_print_vec) {
            cout << vec << endl;
        }
    }
}
