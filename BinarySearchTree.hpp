//Ana Lopez
//SID:
//AO5
//SUB. Day: May 27, 2021
#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
//https://github.com/saharathkleips/DataStructures/blob/master/Project_10/BSTree.cpp
#include <stdio.h>
#include <iostream>
#include <string>
template <class KeyType , class ValueType>
struct TreeNode{
    KeyType key;
    ValueType value;
    TreeNode <KeyType , ValueType>* parent = nullptr;
    TreeNode <KeyType, ValueType>* right = nullptr;
    TreeNode <KeyType, ValueType>* left = nullptr;
};
//add remove (optional, not needed for the A5 insert and find testing
template <class KeyType , class ValueType >
class BinarySearchTree{
public:
    BinarySearchTree ();
    //recursive helper for destrutor to delete nodes
    void destroy(TreeNode <KeyType , ValueType >*& t);
    ~BinarySearchTree();    //{destroy(root);}
    void insert(KeyType key, ValueType value);  //{insert_helper(root, key, value);}
    //returns the min (left-most leaf)
    KeyType min_key ();
    //TreeNode<KeyType, ValueType>* t
    //returns the max (right-most leaf)
    KeyType max_key ();
    //TreeNode<KeyType, ValueType>* t
    // recursive or iterative key search
    bool search(KeyType key);
    void print_inorder(); //{inorder(root);}
    void print_postorder(); //{postorder(root);}
    void print_preorder(); //{preorder(root);}
private:
    //recursive inorder traversal
    void inorder(TreeNode <KeyType , ValueType >* n);
    
    //recursive postorder traversal
    void postorder(TreeNode <KeyType , ValueType >* n);
    
    //recursive preorder traversal
    void preorder(TreeNode <KeyType , ValueType >* n);
    
    // recursive insert helper function
    void insert_helper(TreeNode<KeyType, ValueType>*& root, KeyType key, ValueType value);
    TreeNode <KeyType , ValueType >* root = nullptr; //trees root
    int count = 0; // node count
    };
template <class KeyType, class ValueType>
BinarySearchTree<KeyType, ValueType>::BinarySearchTree() : count(0), root(nullptr){
    //root = NULL;
}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::destroy(TreeNode <KeyType, ValueType>*& t){
    //delete nodes
    if(t == nullptr){
        return;
    }else
    {
        destroy (t->left);
        destroy (t->right);
        delete t;
        
        t = nullptr;
        count--;
    }
}
template <class KeyType,class ValueType>
BinarySearchTree<KeyType, ValueType>::~BinarySearchTree(){
    destroy(root);
}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::insert(KeyType key, ValueType value){
    insert_helper(root, key, value);
}

template <class KeyType, class ValueType>
KeyType BinarySearchTree<KeyType, ValueType>::min_key(){
    TreeNode <KeyType, ValueType>* ptr = root;
    while(ptr -> left != nullptr){
        ptr = ptr -> left;
    }
    return ptr -> key;
    //retruns the min. LEFT-MOST LEAF
    //int t;
    /*if( t == NULL)
        return NULL;
    else if(t -> left == NULL)
        return t;
    else
        return min_key(t->left);*/
}
template <class KeyType, class ValueType>
KeyType BinarySearchTree<KeyType, ValueType>::max_key(){
    //returns the max. RIGHT-MOST LEAF
    TreeNode<KeyType, ValueType>* ptr = root;
    while(ptr -> right != nullptr){
        ptr = ptr->right;
    }
    /*if(t == NULL)
        return NULL;
    else if(t -> right == NULL)
        return t;
    else
        return max_key(t -> right);*/
    return ptr -> key;
}
template <class KeyType, class ValueType>
bool BinarySearchTree<KeyType, ValueType>::search(KeyType key){
    //recursive or iterative key search
    //hashing??
    TreeNode<KeyType, ValueType>* ptr = root;
    while(ptr != nullptr){
        if(key < ptr->key){
            ptr = ptr->left;
        }
        else if(key > ptr ->key){
            ptr = ptr->right;
        }
        else {
            return true;
        }
    }
    return false;
}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>:: print_inorder()     {inorder(root);}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::print_postorder()    {postorder(root);}
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::print_preorder()     {preorder(root);}
//recursive inorder traversal
//void inorder(TreeNode <KeyType , ValueType >* n);
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::inorder(TreeNode<KeyType, ValueType>*n){
    //n
    if(n == nullptr){
        return;
    }
    else{
        inorder(n->left);
        std::cout << n->key << std::endl;
        inorder(n->right);
    }
}
//recursive postorder traversal
//void postorder(TreeNode <KeyType , ValueType >* n);
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::postorder(TreeNode <KeyType, ValueType>*n){
    //n
    if(n == nullptr){
        return;
    }
    else{
        postorder(n -> left);
        postorder (n -> right);
        std::cout << n -> key << std::endl;
    }
}
//recursive preorder traversal
//void preorder(TreeNode <KeyType , ValueType >* n);
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::preorder(TreeNode <KeyType, ValueType>*n){
    //n
    if(n == nullptr){
        return;
    }
    std::cout << n -> key << std::endl;
    preorder(n -> right);
    preorder(n -> left);
}
// recursive insert helper function
//void insert_helper(TreeNode<KeyType, ValueType>*& root, KeyType key, ValueType value);
template <class KeyType, class ValueType>
void BinarySearchTree<KeyType, ValueType>::insert_helper(TreeNode <KeyType, ValueType>*& root, KeyType key, ValueType value){
    //root???
    if(count == 0){
        root = new TreeNode<KeyType, ValueType>;
        root -> value = value;
        root -> key = key;
        count++;
        return;
    }
    if(key <= root ->key){
        if(root -> left != nullptr){
            insert_helper(root -> left, key, value);
        }
        else{
            root->left = new TreeNode<KeyType, ValueType>;
            root->left->value = value;
            root->left->key = key;
            root->left->parent = root;
            count++;
        }
    }
    else if(key >= root -> key)
    {
        if(root -> right != nullptr){
            insert_helper(root -> right, key, value);
        }
       
    else {
        root->right = new TreeNode<KeyType, ValueType>;
        root->right->value = value;
        root->right->key = key;
        root->right->parent = root;
        count++;

        }
    }
}
//TreeNode <KeyType , ValueType >* root = nullptr; //trees root
//int count = 0; // node count
//};

#endif /* BinarySearchTree_hpp */
