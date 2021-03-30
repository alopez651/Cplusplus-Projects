//// Name:  Ana Lopez
///// SSID: 1729539
/////  Assignment  #: 2/
////  Submission  Date: 3/23/21//
#ifndef  _DYNARRAY_HPP
#define  _DYNARRAY_HPP
#include  <iostream>
#include "Container.hpp"
#include  <iostream>
#include "Container.hpp"


template  <class T>
class  DynArray : public  Container <T>
{
    public:
        DynArray <T>() : memsize (0),  _data(nullptr) {};
        DynArray <T>(int size, std:: initializer_list <T> il);
        DynArray <T>(const DynArray <T>& arr1);
        //DynArray <T>(const DynArray <T>& arr2);
        virtual ~DynArray <T>();
        // TODO A2: override  all  container  virtual  functions
        //
        // create  the  dynamic  array  with  size s
        bool resize(int s) override;
    
        //  Checks  if the  container  has no  elements
        bool empty() const override;
    
        //  returns  The  number  of  elements  in and/or size of the  container.
        // for an array  size  and  memsize  will be the  same
        int  size() override;
    
        T* begin() const override;
        T* end() const override;
    
        // For a container c, the  expression
        // c.front () is  equivalent  to *c.begin(),  undefined  if  empty()
        T& front() override;
    
        // For a non -empty  container c, the  expression
        // c.back() is  equivalent  to *std::prev(c.end()),  undefined  if  empty
        T&  back() override;
    
        // std:: out_of_range  exception  thrown  if !( position  < size ()).
        T& at(int position) override;
        T& operator [] (int  position) override;
    
        // If size() is 0, data() may or may  not  return a null  pointer.
        T* data() override;
        const T* data()  const override;
    
    private:
        int  memsize = 0;
        T* _data = nullptr;
};
//create template for each w/implementation
//********* ] ******* fix keyboard*******copy*********
//destr
template <class T>
DynArray<T>::~DynArray()
{
    delete [] _data;
}

template <class T>
bool DynArray<T>::resize (int s)
{
    if (_data != nullptr)
    {
        delete [] _data;
        //delete [] memsize;
    }
    memsize = s;
    //http://www.cplusplus.com/reference/new/nothrow/
    _data = new (std::nothrow) T[memsize];
    //memsize = new (nonthrow) T[_data];
    if (_data == nullptr)
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
bool DynArray<T>::empty() const     //check for error
{
    return memsize == 0;
    //return _data[0];
}
////******* ] *******
template <class T>
int DynArray<T>::size()
{
    return memsize;
    //return _data;
}

template <class T>
T* DynArray<T>::begin() const   //a01
{
    return memsize ? &_data[0] : nullptr;
}

template <class T>  //ao1
T* DynArray<T>::end() const
{
    return begin() + memsize;
    //return memsize;
}

template <class T>
T& DynArray<T>::front()
{
    return *begin();
    //return end();
}

template <class T>
T& DynArray<T>::back()
{
    // c.back() is  equivalent  to *std::prev(c.end()),  undefined  if  empty
    return *(std::prev(end()));
    //return *(prev(c.end()));
    //retrun begin();
}

template <class T>
T& DynArray<T>::at(int position)
{
    if (position < 0 || position >= memsize) //fix _data
    {
        std::string error = "out of range";
        throw(error);
    }
    return _data[position];
}

template <class T>
T* DynArray<T>::data()
{
    if (empty())
    {
        return nullptr;
    }
    else
    {
        return _data;
    }
}

template <class T>
const T* DynArray<T>::data() const
{
    if (empty())
    {
        return nullptr;
    }
    else
    {
        return _data;
    }
}

template <class T>
T& DynArray<T>::operator [] (int position)
{
    return _data[position];
}
template <class T>
DynArray<T>::DynArray(int size, std::initializer_list <T> il)
{
    _data = new T[size];
    //auto a01 cpp
    for (auto x: il)
        //int i;
        //for(auto x : i)
    {
        _data[memsize] = x;
        //_data[memsize] = i;
        //return memsize;
        memsize++;
    }
}

template <class T>
DynArray<T>::DynArray(const DynArray <T>& arr1)
{
    _data = new T[arr1.memsize];
    for (auto x: arr1)
    {
        
        _data[memsize] = x;
        memsize++;
    }
}
#endif
