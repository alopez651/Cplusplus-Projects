//// Name:           Ana Lopez & 1729539
/////  Assignment  #: 2
///Submission  Date: 3/23/21//
#ifndef  _CONTAINER_HPP
#define  _CONTAINER_HPP
#include <iostream>

template <class T>
class Container
{
    public:
        // destructor
        virtual ~Container() {};
        
        // create  the  dynamic  array  with  size s
        virtual bool resize(int s) = 0;
        
        //  Checks  if the  container  has no  elements
        virtual bool empty() const = 0;
        
        //  returns  The  number  of  elements  in and/or size of the  container.
        // for an array  size  and  memsize  will be the  same
        virtual  int  size() = 0;
        
        virtual T* begin() const = 0;
        virtual T* end() const = 0;
        
        // For a container c, the  expression
        // c.front () is  equivalent  to *c.begin(),  undefined  if  empty()
        virtual T& front() = 0;
        
        // For a non -empty  container c, the  expression
        // c.back() is  equivalent  to *std::prev(c.end()),  undefined  if  empty
        virtual T&  back() = 0;
        
        // std:: out_of_range  exception  thrown  if !( position  < size ()).
        virtual T& at(int position) = 0;
        
        // If size() is 0, data() may or may  not  return a null  pointer.
        virtual T* data() = 0;
        virtual const T* data()  const = 0;
        
        //  return  Reference  to the  requested  element.
        virtual T& operator [] (int  position) = 0;
        
};
#endif

