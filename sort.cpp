Sort::Sort(Vector<int> (*t_func)(Vector<int>), int t_size): func(t_func), size(t_size) {

};

Sort::doit() {
    this->sorted = this->func(original);
};
