#ifndef VECTOR_H
#define VECTOR_H

#include <algorithm> // std::copy std::rotate
#include <iostream>  // std::cout std::endl

using std::copy;
using std::rotate;
using std::cout;
using std::endl;


template <class T>
class myVector
{
    int size_v;   // the size
    T *elem; // pointer to the elements (or 0)
    int space;    // number of elements plus number of free slots
public:
    myVector() : size_v{0}, elem{nullptr}, space{0} {} // default constructor

    explicit myVector(int s) : size_v{s}, elem{new T[s]}, space{s} // alternate constructor
    {
        for (int i = 0; i < size_v; ++i)
            elem[i] = 0; // elements are initialized
    }

    myVector(const myVector &src) : size_v{src.size_v}, elem{new T[src.size_v]}, space{src.space} // copy constructor
    {
        copy(src.elem, src.elem + size_v, elem); // copy elements - std::copy() algorithm
    }

    myVector &operator=(const myVector &src) // copy assignment
    {
        T *p = new T[src.size_v];       // allocate new space
        copy(src.elem, src.elem + src.size_v, p); // copy elements - std::copy() algorithm
        delete[] elem;                            // deallocate old space
        elem = p;                                 // now we can reset elem
        size_v = src.size_v;
        return *this;  // return a self-reference
    }

    ~myVector() {
        delete[] elem; // destructor
    }

    T &operator[](int n) {
        return elem[n]; // access: return reference
    }

    const T &operator[](int n) const {
        return elem[n];
    }

    int size() const {
        return size_v;
    }

    int capacity() const {
        return space;
    }

    T* getElem() const
    {
        return elem;
    }

    void resize(int newsize) // growth
    // make the myVector have newsize elements
    // initialize each new element with the default value 0.0
    {
        reserve(newsize);
        for (int i = size_v; i < newsize; ++i)
            elem[i] = 0; // initialize new elements
        size_v = newsize;
    }

    void push_back(T d)
    // increase myVector size by one; initialize the new element with d
    {
        if (space == 0)
            reserve(8);         // start with space for 8 elements
        else if (size_v == space)
            reserve(2 * space); // get more space
        elem[size_v] = d;       // add d at end
        ++size_v;               // increase the size (size_v is the number of elements)
    }

    void reserve(int newalloc)
    {
        // never decrease allocation
        // allocate new space

        // copy old elements
        // deallocate old space

        if (newalloc > space)
        {
            T* tempAr = new T[newalloc];

            for (int index = 0; index < size_v; ++index)
            {
                tempAr[index] = elem[index];
            }

            for (int index = size_v; index < newalloc; ++index)
            {
                T temp{};
                tempAr[index] = temp;
            }

            delete [] elem;
            elem = tempAr;
            tempAr = nullptr;

            space = newalloc;
        }
    }

    using iterator = T *;
    using const_iterator = const T *;

    iterator begin() // points to first element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    const_iterator begin() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[0];
    }

    iterator end() // points to one beyond the last element
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    const_iterator end() const
    {
        if (size_v == 0)
            return nullptr;
        return &elem[size_v];
    }

    // NEEDS TO BE FIXED
    // status: FIXED
    iterator insert(iterator p, const T &val) // insert a new element val before p
    {
        iterator tempPtr = nullptr;

        // make sure we have space
        if (size_v >= space)
        {
            reserve(1);
        }

        // pick the last free element, and then shift all elements of the array to the right
        // until you hit wherever the p iterator is pointing to
        for (tempPtr = &elem[size_v]; tempPtr > p; --tempPtr)
        {
            *tempPtr = *(tempPtr - 1);
        }

        tempPtr = nullptr;

        // the place to put the value
        *p = val;

        // copy element one position to the right
        // insert value

        ++size_v;

        return p; // temp remove & replace // use to be return nullptr
    }

    iterator erase(iterator p) // remove element pointed to by p
    {
        if (p == end())
            return p;
        for (iterator pos = p + 1; pos != end(); ++pos)
            *(pos - 1) = *pos; // copy element one position to the left
        //delete (end() - 1);
        --size_v;
        return p;
    }

    void print() const
    {
        for (int index = 0; index < space; ++index)
        {
            cout << elem[index] << " ";
        }
    }
};

#endif // VECTOR_H
