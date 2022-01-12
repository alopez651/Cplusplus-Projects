//Ana Lopez
//SID: 1729539
//A05
//Sub. Data: 05/27/2021
#ifndef  LinkedList_hpp
#define  LinkedList_hpp
#include <iostream>
#include <string>
#include <stdio.h>
//***********check for spelling and returns*************
//check for revision temp swap to ptr, ****ERROR
//https://stackoverflow.com/questions/15583604/implicit-instantiation-of-undefined-template
template <class  NodeType >
struct  Node{
    NodeType  data;
    Node <NodeType>* next = nullptr;
    Node <NodeType>* prev = nullptr;
};
//adding iter class
template <class NodeType>
class ListIterator;
template <class  NodeType >
class  LinkedList{
    public: //OPTION GETTER Node<NodeTyoe>* Head();
    //add insert, erase(might need start(begin) and end function for it)<---look up
        LinkedList (); // construct  an empty  list
        LinkedList <NodeType >(const LinkedList <NodeType >& that);
        LinkedList <NodeType >& operator=(const LinkedList <NodeType >& that);
        virtual ~LinkedList (); // delete  all  nodes
        int  size ();    //  return  node  count
        bool  empty (); //  check if  empty
        bool search(const NodeType& item) const;
        void  insert_front(const  NodeType& item);
        NodeType  remove_front ();
        void  insert_back(const  NodeType& item);
        NodeType  remove_back ();
        void clear();// remove  all  nodes
        Node<NodeType>* Head(); //try getter
        Node<NodeType>* Tail();
    //friend A04.cpp
    //make new class for friend <Node>
        template<class NodeType2>
        friend LinkedList<NodeType2>list_union (const LinkedList<NodeType2>& u, const LinkedList <NodeType2>& v);
        template<class NodeType2>
        friend LinkedList<NodeType2>list_intersection (const LinkedList<NodeType2>& u, const LinkedList <NodeType2>& v);
    //(A05)may need an erase(Iterator& iter) method to linkedlist, refer to Ch-6
    // insert(iterator, elem) //need for insert min
    // erase(iterator) // need for remove min
    ListIterator <NodeType> begin();
    ListIterator <NodeType> end();
    void insert(const ListIterator<NodeType>& iter, const NodeType& item);  //elem
    void erase(const ListIterator<NodeType>& iter);
    //bool find(NodeType& item) const;
    //int* begin();
    template <class NodeType2>
    friend std::ostream& operator << (const LinkedList<NodeType2>& list, std::ostream& out);
    private:
    //https://www.out4mind.com/en/doubly-linked-list-with-class-templates-part-i/
        Node <NodeType>* head = nullptr;   //iter     DataType
        // optional  tail , useful  for  back  operations
        Node <NodeType>* tail = nullptr;
        int n = 0;   //node  counter                  DataType
};
//template for iter

template <class NodeType>
LinkedList<NodeType>::LinkedList() : n(0), head(nullptr), tail(nullptr) {//: n(0), head(nullptr){
   /* head = new Node <NodeType>();       //DataType
    tail = new Node <NodeType>();      */ //DataType
}
template <class NodeType>
LinkedList<NodeType>::~LinkedList(){
    if(!empty()){
        clear();
    }
   /* clear();
    delete head;
    delete tail;*/
}
template <class NodeType>
int LinkedList<NodeType>::size(){
    return n;
}
template <class NodeType>
bool LinkedList<NodeType>::empty(){
   // return (n == 0);
    //insert priv. func.
    return (head == nullptr && tail == nullptr);
    //return (head -> next==NULL)
}
template <class NodeType>
bool LinkedList<NodeType>::search(const NodeType& item) const{
    Node<NodeType>* ptr = head;
    while(ptr != nullptr){
        if(ptr->data == item){
            return true;
        }
        ptr = ptr->next;           //ptr = ptr->prev;
    }
    return false;
}
template <class NodeType>
void LinkedList<NodeType>::insert_front(const NodeType& item){
    if(empty()){        //head goes first, insert back tail goes 1st
        //erase newNode to head
        //Node<NodeType> *newNode = new Node<NodeType>();
        head = new Node<NodeType>;
        head -> data = item;
        tail = head;
    }
    else{
        /*if(head == nullptr){
            head = newNode;
            return;
        }*/
        //newNode-> next = head;
        head-> prev = new Node<NodeType>;
        head->prev->data = item;
        head->prev->next = head;
        head= head-> prev;
    }n++;
}
template<class NodeType>
NodeType LinkedList<NodeType>::remove_front(){ //check typename
    if(empty()){
        std::cout << "List is empty" << std::endl;
    }
    NodeType dataValue = head->data;
    if(size() == 1){
        delete head;
        tail = nullptr;
        head = nullptr;
    }
    else{
        //make *temp = to head(f)<-A04
        Node<NodeType>* temp = head;
        head->next->prev = nullptr;
        head = head->next;
        delete temp;
    }
    n--;
    //return dataValue->next;
    return dataValue;
}
template <class NodeType>
void LinkedList<NodeType>::insert_back(const NodeType& item){
    if(empty()){
    tail = new Node<NodeType>();
    tail-> data = item;
    head = tail;
    }
    else{
        tail -> next = new Node<NodeType>;
        tail->next->data = item;
        tail->next->prev = tail;
        tail = tail->next;
    }
    n++;
   /* if(head == nullptr){
    }
    n++;
   // newNode -> prev= temp;*/
}
template <class NodeType>
NodeType LinkedList<NodeType>::remove_back(){
    //creating a new ptr
    //use tail for temp
    if(empty()){
        std::cout << "List is empty" << std::endl;
    }
    NodeType dataValue = tail->data;
    if(size() == 1){
        delete tail;
        head = nullptr;
        tail = nullptr;
    }
    else{
        Node<NodeType>* temp = tail;
        tail->prev->next = nullptr;
        tail = tail->prev;
        delete temp;
        //delete tail;
    }
    n--;
    return dataValue;
}
template<class NodeType>
void LinkedList<NodeType>::clear(){     //removes nodes
    //int counter = 0;
    Node<NodeType>* ptr;
    while(head != nullptr){     ////head=tail-> prev
        //LinkedList<NodeType> *remove = tail->prev;      //delete to remove
        ptr = head ->next;
        delete head;
        //delete ptr;
        head = ptr;
       // counter++;
    }
    head = nullptr;
    tail = nullptr;
    //NodeType head = nullptr;
   //NodeType tail = nullptr;
    n=0;
    ///std::cout << "Released" << counter << "nodes from memory" << std::endl;
}
template <class NodeType>
LinkedList<NodeType>::LinkedList(const LinkedList <NodeType>& that)
{
    *this = that;
    //return *that;
}
template <class NodeType>
LinkedList<NodeType>& LinkedList<NodeType>::operator =(const LinkedList<NodeType>& that)
{
    if(this != &that)
    {
        if(!empty()){
            clear();
        }
        //***ptr
        Node<NodeType>* ptr =that.tail;
        while(ptr != nullptr){
            insert_front(ptr->data);
            ptr= ptr->prev;
        }
    }
    return *this;      //return *that;
}
//getter, make then return eachother
template <class NodeType>
Node<NodeType>* LinkedList<NodeType>::Head(){
    return head;
}
template <class NodeType>
Node<NodeType>* LinkedList<NodeType>::Tail(){
    return tail;
}
//void insert(const ListIterator<NodeType>& iter, const NodeType& elem);
//void erase(const ListIterator<NodeType>& iter);
/*template <class NodeType>::find(NodeType& item) const{
    Node<NodeType>* ptr = head;
    while(ptr != nullptr){
        if(ptr -> data == item){
            return true;
        }
        ptr = ptr->next;
    }return false;
}*/

template <class NodeType>
ListIterator<NodeType> LinkedList<NodeType>::begin(){    //head
    return ListIterator<NodeType>(head);
}
template <class NodeType>
ListIterator<NodeType> LinkedList<NodeType>::end(){
    return ListIterator<NodeType>(tail->next);        //->next
}
template <class NodeType>
void LinkedList<NodeType>::insert(const ListIterator<NodeType>& iter, const NodeType& item){
    //need to insert min
    Node<NodeType>* temp = new Node<NodeType>;
    temp-> data = item;
    if(empty ()){
        head = temp;//dataValue;
        tail = temp;
        //tail = ptr;
    }
    else if (iter == end()){
        //swap function???
        temp -> prev = tail;
        //tail -> next = ptr;
        tail -> next = temp;
        //tail = ptr;
        tail = temp;
    }
    else if(size() == 1 || iter == begin()){
        //ptr-> next = iter.priorityNode;
        temp -> next = iter.priorityNode;
        //elem.priorityNode -> prev -> next = ptr;
        iter.priorityNode -> prev = temp;//ptr;
        ////iter.priorityNode -> prev = temp;//ptr;
        head = temp;
    }
    else {
        temp -> next = iter.priorityNode;
        temp -> prev = iter.priorityNode -> prev;
        iter.priorityNode -> prev -> next = temp;
        iter.priorityNode->prev = temp;
    }
    //q++;
    n++;
}
template <class NodeType>
class ListIterator {
public:
ListIterator(Node<NodeType>* v)
{
    priorityNode = v;
}
NodeType& operator *()
{
    return priorityNode->data;
};
bool operator ==(const ListIterator& p) const
{
    return priorityNode == p.priorityNode;
};
bool operator !=(const ListIterator& p) const
{
    return priorityNode != p.priorityNode;
}
ListIterator& operator++()
{
    priorityNode = priorityNode->next;
    return *this;
}
ListIterator& operator--()
{
    priorityNode = priorityNode->prev;
    return *this;
}
friend class LinkedList<NodeType>;
private:
Node<NodeType>* priorityNode;
};

template <class NodeType>
void LinkedList<NodeType>::erase(const ListIterator<NodeType>& iter){
    //need to remove min
    if(iter.priorityNode == nullptr){
        std::cout << "ERROR";
        //std::endl;
    }
    else if(iter == begin()){
        head = head -> next;
        delete iter.priorityNode;
        head -> prev = nullptr;
    }
    else if(iter.priorityNode == tail){
        tail = tail-> prev;
        delete iter.priorityNode;
        tail -> next = NULL;
    }
    else if(size() == 1){
        delete iter.priorityNode;
        head = nullptr;
        tail = nullptr;
    }
    else if(empty()){
        std::cout << "Error" << std::endl;
    }
    else{
        //fix and put in place
        //Node<NodeType>* ptr = iter.priorityNode;
        Node<NodeType>* temp = iter.priorityNode;
        iter.priorityNode -> next -> prev = iter.priorityNode->prev;    //error
        iter.priorityNode -> prev -> next = iter.priorityNode->next;    //error
        //stackoverflow error
    }
    n--;
}
template <class NodeType2>
std::ostream& operator << (std::ostream& out, const LinkedList<NodeType2>& list){
    Node<NodeType2>* ptr = list.Head();
    while(ptr != nullptr){
        out << ptr -> data << std::endl;
        ptr = ptr -> next;
    }
    return out;
}

#endif
