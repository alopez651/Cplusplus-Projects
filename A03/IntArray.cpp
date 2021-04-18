//#pragma once
//#ifndef INT_ARRAY_H
//#define INT_ARRAY_H
#include <iostream>
#include <string>
#include <cmath>
#include "IntArray.h"
//
// Name:         Your First Name & Last Name & Student ID Number
// Assignment #: 3  Submission Date: 4/15/21
//


//
// A3 Interface to Implement, can reuse code from A1 & A2
//
//class IntArray {
//public:
    //constructors and destructors
    IntArray::IntArray(bool sorted)//overloaded   // = true
    {
        sorted = true;
    }
    IntArray::IntArray(int item, bool sorted)//overloaded // = true
    {
        _data = new int [memsize++];
        *_data = item;
        
    }
    IntArray::IntArray(IntArray& arr)        //copy
    {
        _data = new int [arr.memsize];
        for(auto x: arr)
        {
            _data[memsize] = x;
            memsize++;
        }
        sorted = arr.sorted;
    }
    IntArray::~IntArray()                           //destructor
    {
        //if(_data)
            delete [] _data;
    }

    //Member functions

    //delete all elements, set memsize to 0
    void IntArray::clear()
    {
        memsize = 0;
        sorted = true;
        if(_data != nullptr)
        {
            delete [] _data;
        }
        _data = nullptr;
    }

    // insert an item
    void IntArray::insert(int item)// removed -> bool sorted = true);
    {
        IntArray tmp(*this);
        if(_data != nullptr)
        {
            clear();
        }
        _data = new int[tmp.size() + 1];
        for(auto x: tmp)
        {
            _data[memsize] = x;
            memsize++;
        }
        _data[memsize] = item;
        memsize++;
        if(size() > 1)
        {
            sorted = false;
        }
    }

    //recursive array reverse
    void IntArray::reverse(int first, int last, int last2)
    {
        //int first, last, last2;
        std::swap (first, last);
        int tmp = _data[first];
        _data[first] = _data[last];
        _data[last] = tmp;
        //int start;
        if(int start = size() / 2 || size() <= 1)
        {
            return;
        }
        else
        {
            std::swap(start, last2);
            std::reverse(start + 1, last2 -1);
        }
       // else
       //{
            std::reverse(0, size() -1);
        //}
    }

    //implement a n^2 sorting algorithm     //Ch 3.1 Goodrich
    //optional: allow descending sort
    void IntArray::sort(bool asc)//ascending by default //= true
    {
        
        if(size() > 1)
        {
            for(int i = size() - 1; i > 0; i--)
            {
                for(int j = 0; j < i; j++)
                {
                    std::swap(i,j);
                    if(_data[j] > _data[j+1])
                    {
                        std::swap(j, i);    //i+1
                    }
                }
            }
            if(asc)
            {
                sorted = true;
            }
           // else
           // {
              //  reverse();
                //sorted = disc;
            //}
        }
    }

    // Binary search: either recursive or iterative
    // input: requires a sorted array
    int IntArray::binary_search(int key, int fr, int lt)            //page 395 Goodrich
    {
        if(lt > fr)
        {
            std::cout << "Number was not found" << std::endl;
            return -1;
        }
        if(sorted)
        {
            int mid = floor((lt + fr) / 2);
            int n = at(mid);
            if(n == key)
            {
                return 0;
            }
            else if(key < n)
            {
                return binary_search(key, lt, mid - 1);
            }
            else
            {
                return binary_search(key, fr, mid + 1);
            }
        }
        return binary_search(key, size() - 1, 0);
    }

    // iterative linear search
    // input: sorted or unsorted array
    int IntArray::search(int key)
    {
        for(auto x: *this)
        {
            if(key == x)
            {
                return key;
            }
        }
        return -1;
    }

    //delete an item, create a new array memsize-1
    //if sorted use binary search, otherwise use linear search
    void IntArray::remove(int item)
    {
        for(int i = 0; i < memsize; i++)
        {
            if(_data[i] == item)
            {
                for(int t = i; t < memsize-1; t++)
                {
                    _data[t] = _data[t+1];
                }
            }
            _data--;
            break;
        }
    }

    //A1 & A2 member functions
    int IntArray::size()
    {
        return memsize;
    }
    int* IntArray::begin()
    {
        return memsize ? &_data[0] : nullptr;
    }
    int* IntArray::end()
    {
        return begin() + memsize;
    }
    int& IntArray::front()
    {
        return *begin();
    }
    int& IntArray::back()
    {
        return *(std::prev(end()));
    }
    int* IntArray::data()
    {
        if(front())     //check if front is error
        {
            return nullptr;
        }
        else
        {
            return _data;
        }
    }
    const int* IntArray::data() const
    {
        if (data())     //data might be error
        {
            return nullptr;
        }
        else
        {
            return _data;
        }
    }

    int& IntArray::at(int position)
    {
        if(position < 0 || position >= memsize)
            throw std::out_of_range("invalid");
        else
            return _data[position];
        //return _data[position];
    }

    int& IntArray::operator[](int position)
    {
        return _data[position];
    }
    const int& IntArray::operator[](int position) const//new A3
    {
        return _data[position];
    }

    //copy assignment
    IntArray& IntArray::operator = (const IntArray& rhs)
    {
        if(&rhs != this)
        {
            if(memsize != rhs.memsize)
            {
                if(memsize > 0)
                    delete [] _data;
                memsize = rhs.memsize;
                if(memsize > 0)
                    _data = new int[memsize];
                else
                    _data = NULL;
            }
            for(int i = 0; i < memsize; i++)
            _data[i] = rhs._data[i];
        }
        /*//this ->memsize = memsize;
        this -> memsize = rhs.memsize;
        
        //this ->sorted = sorted;
        this -> sorted = rhs.sorted;
        //this ->_data = _data;
        
        this -> _data = rhs._data;*/
        
        return *this;
    }

/*private:
    bool sorted = true;
    int memsize = 0;
    int* _data = nullptr;
};*/
//#endif
