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
        void popBack();
        void removeElement(String _date, String start_time, String end_time);
        void sort();
        void increseSize();
        bool duplicateElements(V& other);

      //  void print() const;
};

template<typename V>
Vector<V>::Vector()        //sushtoto
{
    size = 0;
    capacity = 10;
    vector = new V [capacity];
}

template<typename V>
Vector<V>::Vector(const Vector& other_vector)        //sushtoto
{
    copy(other_vector);
}
template<typename V>
void Vector<V>::erase()        //sushtoto
{
    delete[] vector;
}

template<typename V>
Vector<V>::~Vector()        //sushtoto
{
    erase();
}

template<typename V>
V* Vector<V>::getVecotor()  
{
    return vector;
}

template<typename V>
size_t Vector<V>::getSize()             //sushtoto
{
    return size;
}

template<typename V>
size_t Vector<V>::getCapacity()
{
    return capacity;
}

template<typename V>
void Vector<V>::resize()         //sushtoto
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
void Vector<V>::copy(const Vector& other)         //sushtoto
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
void Vector<V>::removeElement(String _date, String start_time, String end_time)
{
    for (size_t i = 0; i < size; i++)
    {
        if (vector[i].date == _date && vector[i].startTime == start_time && vector[i].endTime == end_time)
        {
            vector[i] = vector[i + 1];
        }
    }
    size--;
}

template<typename V>
void Vector<V>::sort()
{
    for (size_t i = 0; i < size; i++)
    {
        if (meetings[i].convertDateToInt(meetings[i].getDate())> meetings[i+1].getDate())
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
bool Vector<V>::duplicateElements(V& other)
{
    for (size_t i = 0; i < size; i++)
    {
        if (date != other.date || name != other_name || note != other.note || startTime != other.startTime || endTime != other.endTime)
        {
            return false;
        }
    }
    return true;
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

/*
template<typename V>
void Vector<V>::print() const
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }*=
}*/