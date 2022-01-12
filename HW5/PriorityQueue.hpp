
#ifndef PriorityQueue_hpp_hpp
#define PriorityQueue_hpp_hpp

#include <iostream>
#include <string>
#include "LinkedList.hpp"
#include <stdio.h>
/*template <class  NodeType >
struct  Node{
    NodeType  data;
    Node <NodeType>* next = nullptr;
    Node <NodeType>* prev = nullptr;
};*/
template <class NodeType >
class PriorityQueue{
public:
// call your linked list insert front or back; or insert t sorted
    void insert(NodeType t);
//update linked list to return an Iterator (refer to Goodrich-6.2.3)
//or change to ListIterator to a NodeType*
    //ListIterator <NodeType > find_min(ListIterator <NodeType > iter);
// return the min, may need a find helper function
    NodeType& min();
// remove the min
// if list is already sorted, just remove_front or back
// if list is not sorted, find(min) and remove
// may need to add an erase method to linkedlist, refer to chapter 7
    //void remove_min ();
// check if queue is
    bool is_empty ();
    void remove_min();
    
   // Node<NodeType>* Head(); //try getter
    //Node<NodeType>* Tail();
private:
    LinkedList<NodeType> q;
    /*
    Node <NodeType>* head = nullptr;
    Node <NodeType>* tail = nullptr;*/

};
 /* PriorityQueue_hpp_hpp */
// Updates May Be Needed to A4’s LinkedList
// to make insert and remove easier create a list iterator p243 Goodrich
// or use a NodeType* as iterator
// To support queue operations add the following methods
// to your linkedlist implementation:
// insert(iterator, elem) //need for insert min
// erase(iterator) // need for remove min

template <class NodeType>
void PriorityQueue<NodeType>::insert(NodeType t){
    //t, linkedlist insert_front, insert_back
    if(is_empty()){
        q.insert_front(t);
    }
    else {
        //iter list
        ListIterator<NodeType> iterator(q.begin());
        while(iterator != q.end()){
            if(t <= *iterator){
                q.insert(iterator, t);
                return;
            }
            ++iterator;
        }
        q.insert(iterator, t);
    }
    //call linked list front or back
    /*if(inser_front() == false){
        int index = size;
        NodeType node;
        dataItems[size] = t;
        
        while(node(dataItems[index].getPriority(), dataItems[(index - 1) / 2].getpriority()){
            NodeType node = dataItems[index];
            dataItems[index] = dataItems [(index - 1)/2];
            index = (index - 1) / 2;
        }
              size++;
    }
              else
              throw logic_error("List error!");*/
}
template <class NodeType>
bool PriorityQueue<NodeType>::is_empty(){
            return q.empty();
}
//NodeType& min();, void remove_min();
template <class NodeType>
NodeType& PriorityQueue<NodeType>::min(){
    if(is_empty()){
        std::cout << "Error" << std::endl;
    }
    return q.Head() -> data;
}
template <class NodeType>
void PriorityQueue<NodeType>::remove_min(){
    if(is_empty()){
        std::cout << "Error ";
        //std::endl;
        //throw logic_error;
    }
    q.remove_front();
}
            
#endif
