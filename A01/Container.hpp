//// Name: Ana Lopez
// SSID: 1729539
//  Assignment  #: 1
//  Submission  Date: 03/09/2021
#ifndef  _CONTAINER_HPP
#define  _CONTAINER_HPP
#include  <iostream>
#include  <string>
//#include <vector>


template  <class T, int N>
class  Container {  //std::vector<std::string>  total;
    public:
        using  value_type = T;
        void  add_item(T item);     // output  container  full , if  add_item  cannot  add
        T get_item(int  index );     //throw a string  if index  out of  bounds
        const std::string get_item();
        void  remove_item(T item) ; // remove  first  occurrence  of item
        bool  empty ();                // check of  Container  is  empty
        void  clear ();                // clear  all  contents , assign  value_type
        constexpr  int  size ();      // return  current  number  of  elements  in  container
        T* begin ();
        T* end();

    private:
        int  _size = 0;
        T container[N];
       // int size1;
        //int size2;
    //int coutnt;
      
};// Container  interface

/*  Sample  Template  member  function  definitions */
template  <class T, int N>
constexpr  int  Container <T, N>::size() { return  _size; }

template  <class T, int N>
void  Container <T, N>::clear() {
    for (int i = 0; i <_size; i++)
        container[i] = T(); //or  value_type ();
    _size = 0;}

template  <class T, int N>
T* Container <T, N>::begin() { return  _size ? &container[0] : nullptr; }

template  <class T, int N>
T* Container <T, N>::end() { return  begin() + _size; }
//// TODO: implement  add_item ,get_item ,remove_item , empty//

//template <class T, int N>
//std::Container<T,N>::std::~Container()
//{while (!empty() remove_item();)}

template <class T, int N>
void Container<T, N>::add_item(T item)
{
    container [_size] = item;   //container or items
    _size++;
    //_size.push(item);
    /*int item1 = 0;
    int item2 = 0;//this->std::count -1;
    
    while (item1 <= item2)
    {
        int mid = ((unsigned) (item1 + item2)) >> 1;
        T mid_item = this-> container[mid];
        
        if(mid_item< item)
            item1 = mid + 1;
            else
                item2 = mid - 1;
    }*/
    std::string add_item;
    std::cout << add_item;
    //return;
}

template <class T, int N>
void Container <T, N>::remove_item(T item)
{
    /*int item1;
    int item2;
    for(item1 = 0; item1< _size; i++)                           //container
    {
        if(container[1] == item)
        {
            int item2;
               for(item2t = item1; item2 < _size-1; item2++){              //container
                container[item2] = container[t+1];
            }
        }
    }
}*/
    int i;
    for(i = 0; i< _size; i++)                           //container
    {
        if(container[1] == item)
        {
            int t;
               for(t = i; t < _size-1; t++){              //container
                container[t] = container[t+1];
            }
        }
       _size--;
        break;
    }
}
////const std::string get_item
template <class T, int N>
T Container<T, N>::get_item(int index)
{
    return container[index];
   //return get_item[int index];
}

template<class T, int N>
bool Container< T, N>::empty()
{
    clear();
    _size = 0;
    //return container == NULL;
   return _size == NULL;
}

#endif
