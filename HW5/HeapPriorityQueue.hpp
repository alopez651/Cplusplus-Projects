//
//  HeapPriorityQueue.hpp
//  A05
//
//  Created by Ana Lopez on 5/17/21.
//

#ifndef HeapPriorityQueue_hpp
#define HeapPriorityQueue_hpp
#include "VectorCompleteBinaryTree.hpp"
#include <stdio.h>
#include <istream>
// A class MyComparator must be created with the operator() overloaded
//cpp file is as Comparator -> change MyComparator to Comparator
//check for all edits NodeType, Comparator (check if it need to be MyComparator)
//*****--^ CHECK A05.CPP FILE for correct version ---^
template <class NodeType>
class Compare{
public:
    bool operator() (const typename std::vector<NodeType>::iterator p, const typename std::vector <NodeType>::iterator q) const {
        //error
        return *p <= *q;
    }
};
template <class NodeType, class Comparator>   //typename MyComparator
class HeapPriorityQueue {
public:
  int size() const;                            // number of elements
  bool empty() const;                          // is the queue empty?
  void insert(const NodeType& item);                     // insert element
  const NodeType& min();                              // minimum element
  void remove_min();                            // remove minimum
private:
  VectorCompleteBinaryTree<NodeType> T;                     // priority queue contents
  Comparator isLess;                                    // less-than comparator
                                               // shortcut for tree position
    //add MyComparator
  typedef typename VectorCompleteBinaryTree<NodeType>::Position Position;
    //VectorCompleteBinaryTree<class NodeType> T;
    //Comparator isLess;
};

template <class NodeType, class Comparator>    // number of elements
int HeapPriorityQueue<NodeType,Comparator>::size() const
  { return T.size(); }

template <class NodeType ,class Comparator>    // is the queue empty?
bool HeapPriorityQueue<NodeType, Comparator>::empty() const
  { return size() == 0; }

template <class NodeType, class Comparator>    // minimum element
const NodeType& HeapPriorityQueue<NodeType, Comparator> ::min()
  {return *(T.root());}            // return reference to root element

template <class NodeType, class Comparator>         // insert element
void HeapPriorityQueue<NodeType, Comparator>::insert(const NodeType& item) {
    T.addLast(item);
    Position ptr = T.last();
    while(!T.isRoot(ptr)){
        if(!isLess(ptr, T.parent(ptr))){
            return;
        }
        //swap func.
        T.swap(ptr, T.parent(ptr));
        ptr = T.parent(ptr);
    }
    
 /* T.addLast(e);                           // add e to heap
  Position v = T.last();                  // e's position
  while (!T.isRoot(v)) {                  // up-heap bubbling
     Position u = T.parent(v);
     if (!isLess(*v, *u)) break;          // if v in order, we're done
     T.swap(v, u);                        // ...else swap with parent
     v = u;
  }*/
}
template <class NodeType, class Comparator>        // remove minimum
void HeapPriorityQueue<NodeType,Comparator>::remove_min() {
  if (size() == 1)                       // only one node?
     T.removeLast();                     // ...remove it
  else {
     Position parent = T.root();              // root position
     T.swap(T.root(), T.last());                // swap last with root
     T.removeLast();                     // ...and remove last
    while (T.hasLeft(parent)) {              // down-heap bubbling
     Position child = T.left(parent);
     if (T.hasRight(parent) && isLess(T.right(parent), child))
       child = T.right(parent);                   // v is u's smaller child
     if (isLess(child, parent)) {               // is u out of order?
       T.swap(parent, child);                     // ...then swap
       parent = child;
     }
     else break;                         // else we're done
    }
  }
}
#endif /* HeapPriorityQueue_hpp */
