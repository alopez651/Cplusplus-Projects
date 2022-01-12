//
//  VectorCompleteBinaryTree.hpp
//  A05
//
//  Created by Ana Lopez on 5/17/21.
//

#ifndef VectorCompleteBinaryTree_hpp
#define VectorCompleteBinaryTree_hpp
#include <iostream>
//#include <string>
//#include <regex>
#include <stdio.h>
#include <vector>
//change class
template <class NodeType>
class VectorCompleteBinaryTree {
  //... insert private member data and protected utilities here
    //std::vector<E> *array; //maybe add protected??
public:
    //error with list Postion ?? change try iterator check for others
   typedef typename std::vector<NodeType>::iterator Position;
  VectorCompleteBinaryTree() : V(1) {}            // constructor
  int size() const                          { return V.size() - 1; }    //{ return V.size() − 1;}
  Position left(const Position& p)          { return pos(2*idx(p)); }
  Position right(const Position& p)         { return pos(2*idx(p) + 1); }
  Position parent(const Position& p)        { return pos(idx(p)/2); }
  bool hasLeft(const Position& p) const     { return 2*idx(p) <= size(); }
  bool hasRight(const Position& p) const    { return 2*idx(p) + 1 <= size(); }
  bool isRoot(const Position& p) const      { return idx(p) == 1; }
  Position root()                           { return pos(1); }
  Position last()                           { return pos(size()); }
  void addLast(const NodeType& item)        { V.push_back(item); }
  void removeLast()                         { V.pop_back(); }
  void swap(const Position& p, const Position& q)
    { NodeType temp = *p; *q = temp; *p = *q; }
protected:
    Position pos(int v){
        return V.begin() + v;
    }
    int idx (const Position& p) const {
        return p - V.begin();
    }
private:
    std::vector<NodeType> V;
};
/*template <class NodetType>
int VectorCompleteBinaryTree<NodeType>::size() const {
    return V.size() - 1;
}*/
#endif /* VectorCompleteBinaryTree_hpp */
