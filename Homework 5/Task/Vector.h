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
    void erase();
public:
        Vector();
        Vector(const Vector& other);
        ~Vector();

        V* getVecotor();
        size_t getSize();
        size_t getCapacity();

        Vector& operator= (const Vector& other_vector);

        V& operator[](int i);

        friend std::ostream& operator<<(std::ostream& out, Vector<V> _vector)
        {
            for (size_t i = 0; i < _vector.size; i++)
            {
                out << _vector.vector[i] << " ";
            }
            return out;
        }

        void pushBack(V newElement);
        void removeElement(size_t index);
};

template<typename V>
Vector<V>::Vector()      
{
    size = 0;
    capacity = 5;
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
    V* biggerVector = new V[capacity];

    for (size_t i = 0; i < size; i++)
    {
        biggerVector[i] = vector[i];
    }

    erase();
    vector = biggerVector;
}

template<typename V>
void Vector<V>::copy(const Vector& other)
{
    vector = new V [other.capacity];
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

    vector[size++] = newElement;
}

template<typename V>
void Vector<V>::removeElement(size_t index)
{
    for (int i = index; i < size; i++)
    {
        vector[i] = vector[i + 1];
    }
    size--;
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
V& Vector<V>::operator[](int i)
{
    return vector[i];
}