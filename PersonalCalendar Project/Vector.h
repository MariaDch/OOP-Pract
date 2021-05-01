#pragma once
#include <iostream>
#include "Meeting.h"

template <typename V>
class Vector
{
private:
    V* vector;
    size_t size;
    size_t capacity;

    void copy(const Vector& other);
    void resize();
    void erase();
public:
        Vector();
        Vector(const Vector& other);
        ~Vector();

        V* getVecotor();
        size_t getSize();
        size_t getCapacity();

        Vector& operator= (const Vector& other);
        Vector& operator[](int i);
        friend std::ostream& operator<<(std::ostream& out, Vector<V> vect);

        void pushBack(V newElement);
        void popBack();
        void sort();
        void increseSize();

        void print() const;
};

template<typename V>
Vector<V>::Vector()
{
    size = 0;
    capacity = 10;
    vector = new V [capacity];
}

template<typename V>
Vector<V>::Vector(const Vector& other_vector)
{
    copy(other_vector);
}
template<typename V>
void Vector<V>::erase()
{
    delete[] vector;
}

template<typename V>
Vector<V>::~Vector()
{
    erase();
}

template<typename V>
V* Vector<V>::getVecotor()
{
    return vector;
}

template<typename V>
size_t Vector<V>::getSize()
{
    return size;
}

template<typename V>
size_t Vector<V>::getCapacity()
{
    return capacity;
}

template<typename V>
void Vector<V>::resize()
{
    capacity = size;
    capacity *= 2;
    int* biggerVector = new int[capacity];

    for (size_t i = 0; i < size; i++)
    {
        biggerVector[i] = this->vector[i];
    }

    erase();
    vector = biggerVector;
}

template<typename V>
void Vector<V>::copy(const Vector& other)
{
    vector = new int[other.capacity];
    size = other.size;
    capacity = other.capacity;

    for (size_t i = 0; i < size; i++)
    {
        vector[i] = other.vector[i];
    }
}

template<typename V>
void Vector<V>::pushBack(V newElement)
{
    if (size >= capacity)
    {
        resize();
    }

    vector[size] = newElement;
    size++;
}

template<typename V>
void Vector<V>::popBack()
{
    if (size > 0)
    {
        size--;
    }
}

template<typename V>
inline void Vector<V>::increseSize()
{
    size++;
    if (size >= capacity)
    {
        resize();
    }
}

template<typename V>
Vector<V>& Vector<V>::operator=(const Vector& other_vector)
{
    if (this != &other_vector)
    {
        erase();
        copy(other_vector);
    }

    return *this;
}

template<typename V>
Vector<V>& Vector<V>::operator[](int i)
{
    return vector[i];
}

template <typename V>
std::ostream& operator<<(std::ostream& out, Vector<V> vect)
{
    for (size_t i = 0; i < vect.size; i++)
    {
        out << vect.vector[i] << " ";
    }
    return out;
}

template<typename V>
void Vector<V>::print() const
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }
}