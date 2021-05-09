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
        bool overlapedMeetings(V& other);
        V& findElement(V element);

        int BusyHours();

        void print() const;
};

template<typename V>
Vector<V>::Vector()        //da
{
    size = 0;
    capacity = 10;
    vector = new V [capacity];
}

template<typename V>
Vector<V>::Vector(const Vector& other_vector)        //da
{
    copy(other_vector);
}
template<typename V>
void Vector<V>::erase()        //da
{
    delete[] vector;
}

template<typename V>
Vector<V>::~Vector()        //da
{
    erase();
}

template<typename V>
V* Vector<V>::getVecotor()  
{
    return vector;
}

template<typename V>
size_t Vector<V>::getSize()             //da
{
    return size;
}

template<typename V>
size_t Vector<V>::getCapacity()
{
    return capacity;
}

template<typename V>
void Vector<V>::resize()         //da
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
void Vector<V>::copy(const Vector& other)         //da
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
        if (vector[i].getDate() == _date && vector[i].getStartTime() == start_time && vector[i].getEndTime() == end_time)
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
        String start_time = vector[i].getStartTime();
        String secondStart_time = vector[i].getStartTime();
        //  String secondDate = vector[i + 1].getDate();
        if (vector[i].getDate().convertDateToInt() > vector[i + 1].getDate().convertDateToInt())
        {
            V vect = vector[i];
            vector[i] = vector[i + 1];
            vector[i + 1] = vect;
        }
        if (vector[i].getDate().convertDateToInt() == vector[i + 1].getDate().convertDateToInt())
        {
            if (vector[i].getStartTime().convertTimeToInt() > vector[i + 1].getStartTime().convertTimeToInt())
            {
                V vect = vector[i];
                vector[i] = vector[i + 1];
                vector[i + 1] = vect;
            }
        }
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
bool Vector<V>::overlapedMeetings(V& other)
{
    for (size_t i = 0; i < size; i++)
    {
        int vectorIconvertedStartTime = vector[i].getStartTime().convertTimeToInt();
        int vectorIconvertedEndTime = vector[i].getEndTime().convertTimeToInt();
        
        int otherConvertedStartTime = other.getStartTime().convertTimeToInt();
        int otherConvertedEndTime = other.getEndTime().convertTimeToInt();

        if (vector[i].getDate().validateDate() && vector[i].getStartTime().validateTime(vector[i].getStartTime()) && vector[i].getEndTime().validateTime(vector[i].getEndTime()))
        {
            if (vector[i].getDate() == other.getDate() && vectorIconvertedStartTime >= otherConvertedStartTime && vectorIconvertedEndTime <= otherConvertedEndTime)
            {
                return true;
            }

            if (vector[i].getDate() == other.getDate() && vectorIconvertedStartTime >= otherConvertedStartTime && vectorIconvertedEndTime >= otherConvertedEndTime)
            {
                return true;
            }
        }
    }
    return false;
}

template<typename V>
inline V& Vector<V>::findElement(V element)
{
    for (size_t i = 0; i < size; i++)
    {
        if (vector[i] == element)
        {
            return vector[i];
        }
    }
}


template<typename V>
int Vector<V>::BusyHours()
{
    sort();
    int hours = 0;
    int helperOne = 0;
    int helperTwo = 0;

    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = i; vector[j].getDate() == vector[j + 1].getDate(); j++)
        {
                helperTwo = vector[j].getStartTime().convertTimeToInt() / 100; // 1300 -> 13
                helperOne = vector[j].getEndTime().converTimeToInt() / 100;  // 1500 -> 15
                hours += helperOne-helperTwo;
        }
    }
    return hours;
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


template<typename V>
void Vector<V>::print() const
{
    for (size_t i = 0; i < size; i++)
    {
        std::cout << vector[i] << std::endl;
    }
}