#pragma once
#include <iostream>

template <typename V>
class Vector
{
private:
    V* vector;
    size_t size;
    size_t capacity;

    void copy(const Vector& other);
    void resize();
public:
        Vector();
        Vector(const Vector& other);
        Vector& operator= (const Vector& other);
        ~Vector();

        void pushBack(int newElement);
        void popBack();
        void print() const;

};

template<typename V>
Vector<V>::Vector()
{
    size = 0;
    capacity = 8;
    vector = new V [capacity];
}

template<typename V>
Vector<V>::Vector(const Vector& other_vector)
{
    copy(other_vector);
}

template<typename V>
Vector<V>::~Vector()
{
    delete[] vector;
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

    delete[] vector;
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
void Vector<V>::pushBack(int newElement)
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
Vector<V>& Vector<V>::operator=(const Vector& other_vector)
{
    if (this != &other_vector)
    {
        delete[] vector;
        copy(other_vector);
    }

    return *this;
}

template<typename V>
void Vector<V>::print() const
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }
}