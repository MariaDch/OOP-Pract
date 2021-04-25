/*#include "Vector.h"

template<typename V>
Vector<V>::Vector() 
{
    size = 0;
    capacity = 8;
    vector = new int[capacity];
}

template<typename V>
Vector<V>::Vector(const Vector& other_vector)
{
    size = other_vector.size;
    capacity = other_vector.capacity;
    vector = other_vector.vector;
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
}*/