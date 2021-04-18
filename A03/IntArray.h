// Name:Ana Lopez
// Student ID: 1729539
// Assignment #: 3
//Submission Date: 4/15/21
#pragma once
#ifndef INT_ARRAY_H
#define INT_ARRAY_H
//#include "IntArray.cpp"
#include <iostream>
//
// A3 Interface to Implement, can reuse code from A1 & A2
//
//INTERFACE
class IntArray {
public:
    //constructors and destructors
    IntArray(bool sorted = true);            //overloaded
    IntArray(int item, bool sorted = true);//overloaded
    IntArray(IntArray& arr);        //copy
    ~IntArray();                           //destructor

    //Member functions

    //delete all elements, set memsize to 0
    //clear to delete the array contents;
    void clear();
        
    // insert an item, IntArray can be unsorted.
    // Sorted by default.
    void insert(int item);  //, bool sorted = true

    //recursive array reverse
    void reverse(int first, int last, int last2);

    //implement a n^2 sorting algorithm     //Ch 3.1 Goodrich
    //optional: allow descending sort
    void sort(bool asc = true);//ascending by default

    // Binary search: either recursive or iterative
    // input: requires a sorted array
    int binary_search(int key, int fr, int lt);            //page 395 Goodrich

    // iterative linear search
    // input: sorted or unsorted array
    int search(int key);

    //delete an item, create a new array memsize-1
    //if sorted use binary search, otherwise use linear search
    void remove(int item);

    //A1 & A2 member functions
    int size();
    int* begin(); int* end();
    int& front(); int& back();
    int* data();
    const int* data() const;

    int& at(int position);

    int& operator[](int position);
    const int& operator[](int position) const;//new A3

    //copy assignment
    IntArray& operator=(const IntArray& rhs);

private:
    bool sorted = true;
    int memsize = 0;
    int* _data = nullptr;
};
#endif
