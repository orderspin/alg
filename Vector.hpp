#ifndef VECTOR_H
#define VECTOR_H

template <class T>
struct Vector {
    T *ptr;
    int size;

    Vector(int, T);
    //~Vector();
    //Vector(const Vector &);

    //Vector& operator=(const Vector &);
};

#endif
