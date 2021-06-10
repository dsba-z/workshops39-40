#ifndef SAFE_ARRAY_H_
#define SAFE_ARRAY_H_

#include <cstddef>
#include <algorithm>        // std::min
#include <stdexcept>        // std::out_of_range

template<typename T>
class SafeArray {
public:

    /// The default constructor.
    SafeArray()
        : _arr(nullptr)
        , _size(0)
    {}

    /// Constructor creates an array with \a sz elements of value \a def
    SafeArray(size_t sz, T def /* = ???*/)
        : SafeArray()
    {
        if (sz == 0)
        {
            return;
        }
        _size = sz;
        _arr = new T[_size];
        
        for (size_t i = 0; i < _size; ++i)
        {
            _arr[i] = def;
        }
    }

    /// The copy constructor.
    // Difference here
    SafeArray(const SafeArray& origin)
        : _size(origin._size)
      //, ????
    {
//        _size = origin._size;
        _arr = new T[_size];
        for (size_t i = 0; i < _size; ++i)
        {
            _arr[i] = origin._arr[i];
        }
    }

    /// Constructor with initializer list
    SafeArray(std::initializer_list<T> vals)
//    ????
    {

    }


    /// The Destructor. Implements RAII closing part.
    ~SafeArray()
    {
        delete [] _arr;
    }


    /// The Copy Assignment operator overloading.
//    <output type> operator = (<input type> rhv)
//    {

//    }

public:
    /// Resizes the array.
    void resize(size_t newSz, T def /* = ???*/)
    {
        // edge cases


        // create a new array, copy elements of the old array, and remove the old

        // if new array is bigger, need to fill the difference

    }


    /// Getting the ref to i-th element with no checking out of range.
    T& operator [] (size_t i) noexcept { return _arr[i]; }
    /// Const version
//    /* <output type (const)> */ operator [] (/* input type */) /*???*/ noexcept { /* ??? */ }

    /// Getting the ref to i-th element with checking out of range.
    /// Regular version and const version
    T& at(size_t i)
    {
        if (i >= _size)
        {
            throw std::out_of_range("Index out of range\n");
        }
        return _arr[i];
    }
    /// Const version



    /// getters
    size_t getSize() const { return _size; }
    const T* getPtr() const { return _arr; }

private:

    /// Auxialiary method swapping two array objects with a managed resource
    /// correctly. Method guarantees that it doesn't throw under any conditions.
    static void swap(/*input arguments*/) noexcept
    {
        // use std::swap
    }

private:
    T* _arr;                ///< Actual resource handler.
    size_t _size;           ///< Stores size of an array.
};// SafeArray


//template<typename T>
//std::ostream& operator << (std::ostream& s, /*input type*/)
//{
//    // write the array as [10, 20, 30]
//    // using square brackets and commas
//}



#endif // SAFE_ARRAY_H_
