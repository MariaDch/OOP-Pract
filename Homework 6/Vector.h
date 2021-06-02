#pragma once
#include <iostream>

template <typename V>
class Vector
{
private:
    V* vector;
    size_t size;
    size_t capacity;

    virtual void copy(const Vector& other);
    void resize();
    void erase();
public:
        Vector();
        Vector(const Vector& other);
        ~Vector();

       // V* getVecotor();
        size_t getSize() const;
        //size_t getCapacity();

        Vector& operator= (const Vector& other_vector);

        V& operator[](size_t i);

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
        void removeElement(size_t index);
        V& findElement(V element);
        void print() const;
};

template<typename V>
Vector<V>::Vector()        //
{
    size = 0;
    capacity = 5;
    vector = new V [capacity];
}

template<typename V>
Vector<V>::Vector(const Vector& other_vector)        //
{
    copy(other_vector);
}
template<typename V>
void Vector<V>::erase()        //
{
    delete[] vector;
}

template<typename V>
Vector<V>::~Vector()        //
{
    erase();
}

/*template<typename V>
V* Vector<V>::getVecotor()  
{
    return vector;
}*/

template<typename V>
size_t Vector<V>::getSize() const         //
{
    return size;
}

/*
template<typename V>
size_t Vector<V>::getCapacity()
{
    return capacity;
}*/

template<typename V>
void Vector<V>::resize()         //
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
void Vector<V>::copy(const Vector& other)         //
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
    for (size_t i = 0; i < size; i++)
    {
        if (vector[i].overlapedMeetings(newElement) == true)
        {
            std::cout << "Overlaped meetings.";
            break;
        }
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
void Vector<V>::removeElement(size_t index)
{
    for (size_t i = index; i < size; i++)
    {
        vector[i] = vector[i + 1];
    }
    size--;
}
/*
template <typename V>
void Vector<V>::swap(V& element, V& elem)
{
    V vect = element;
    element = elem;
    elem = vect;
}*/
/*
template<typename V>
void Vector<V>::sort()
{
    for (size_t i = 0; i < size; i++) 
    {
        for( size_t j=i+1; j<size; j++)
        { 
            int start_time = vector[i].getStartTime.getDateOrTime().convertStringToInt();
            int secondStart_time = vector[j].getStartTime().getDateOrTime().convertStringToInt();

            if (vector[i].getDate().getDateOrTime().convertStringToInt() > vector[j].getDate().getDateOrTime().convertStringToInt())
            {
                swap(vector[i], vector[j]);
            }
            else  if (vector[i].getDate().getDateOrTime().convertStringToInt() == vector[j].getDate().getDateOrTime().convertStringToInt())
            {
                if (start_time > secondStart_time)
                {
                    swap(vector[i], vector[j]);
                }
            }
        }
        
    }
}*/

template<typename V>
V& Vector<V>::findElement(V element)
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
V& Vector<V>::operator[](size_t  i)
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