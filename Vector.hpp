#ifndef VECTOR_H
#define VECTOR_H

template <class T>
struct Vector {
    T *ptr;
    int size;

    Vector();
    Vector(int t_size, T t_data);
    ~Vector();
    Vector(const Vector &s_Vector);

    Vector& operator=(const Vector &s_Vector);

    Vector& append(const T &appendItem);
    Vector& append(const Vector &appendVector);
};

template <class T>
Vector<T>::Vector(): size(0), ptr(NULL) {}

template <class T>
Vector<T>::Vector(int t_size, T t_data): size(t_size){
    this->ptr = new T[t_size];
}

template <class T>
Vector<T>::~Vector() {
    delete [] this->ptr;
}

template <class T>
Vector<T>::Vector(const Vector &s_Vector) {
    this->ptr = new T[s_Vector.size];
    this->size = s_Vector.size;
    for(int i = 0; i < this->size; i++) {
        this->ptr[i] = s_Vector.ptr[i];
    }
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector &s_Vector) {
    if (this != &s_Vector) {
        this->ptr = new T[s_Vector.size];
        this->size = s_Vector.size;
        for(int i = 0; i < this->size; i++) {
            this->ptr[i] = s_Vector.ptr[i];
        }
    }
    return *this;
}

template <class T>
Vector<T>& Vector<T>::append(const T &appendItem) {
    T *tmp = new T(this->size + 1);
    for(int i = 0; i < this->size; i++) {
        tmp[i] = this->ptr[i];
    }
    tmp[this->size] = appendItem;
    this->size += 1;
    delete [] this->ptr;
    this->ptr = tmp;
    return this;
}

template <class T>
Vector<T>& Vector<T>::append(const Vector &appendVector) {
    T *tmp = new T(this->size + appendVector.size);
    for(int i = 0; i < this->size; i++) {
        tmp[i] = this->ptr[i];
    }
    for(int i = 0; i < appendVector.size; i++) {
        tmp[this->size + i] = appendVector[i];
    }
    this->size += appendVector.size;
    delete [] this->ptr;
    this->ptr = tmp;
    return this;
}


#endif
