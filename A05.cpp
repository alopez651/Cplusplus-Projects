#include <queue>
#include <iomanip>
#include <ctime>
#include <random>
#include <chrono>
#include <iostream>
#include <stdio.h>
#include "BinarySearchTree.hpp"
#include "HeapPriorityQueue.hpp"
//#include "VectorCompleteBinaryTree.hpp"
#include "PriorityQueue.hpp"
//#include "LinkedList.hpp"
int main (){
    //
    // test priority queue implemented with unsorted linked list //
   int SAMPLES = 1000;
    // use current time as seed for random generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //sort simulation
    std::vector<int> sorted; PriorityQueue <int> pq;
    auto start = std::chrono::high_resolution_clock::now();
    // insert
    for (int i = 0; i < SAMPLES; i++)
    pq.insert(std::rand() % 1000 + 1);
    // sort
    while (!pq.is_empty()){
        sorted.push_back(pq.min()); pq.remove_min();
    }
    auto stop = std::chrono::high_resolution_clock::now();
    std::cout << "Unsorted linkedlist priority queue sequence sorting took: "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast <std::chrono::microseconds >
              (stop - start).count() / 1000. << " milliseconds.\n";
    //end clunky priority queue
    //
    //test stl priority queue adapter as deque (double ended queue/linked list) //
    std::priority_queue<int, std::deque<int>> stl_priority_queue;
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    sorted.clear();
    start = std::chrono::high_resolution_clock::now();
    // insert
    for (int i = 0; i < SAMPLES; i++)
        stl_priority_queue.push(std::rand() % 1000 + 1);
    // sort
    while (!stl_priority_queue.empty()) {
        sorted.push_back(stl_priority_queue.top());stl_priority_queue.pop();}
    
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "STL priority queue time: "
              << std::fixed << std::setprecision(2)       //invalid operands??
              << std::chrono::duration_cast <std::chrono::microseconds >
              (stop - start).count() / 1000. << " milliseconds.\n";
    //end stl
    //
    // vector
    //
    HeapPriorityQueue<int, Compare <int>> heap_priority_queue;
    sorted.clear();
    start = std::chrono::high_resolution_clock::now();
    // insert
    for (int i = 0; i < SAMPLES; i++)
        heap_priority_queue.insert(std::rand() % 1000 + 1);
    // sort
    while (!heap_priority_queue.empty()) {
        sorted.push_back(heap_priority_queue.min());
        heap_priority_queue.remove_min();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "Heap priority queue sequence sorting took: "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast <std::chrono::microseconds >
              (stop - start).count() / 1000. << " milliseconds.\n";
    //
    // test C++ stl::make_heap
    //
    std::vector<int> stl_heap;
    for (int i = 0; i < SAMPLES; i++)
    stl_heap.push_back(std::rand() % 1000 + 1);
    
    std::make_heap(stl_heap.begin(), stl_heap.end());
    sorted.clear();
    start = std::chrono::high_resolution_clock::now();
    while (!stl_heap.empty()) {
        sorted.push_back(stl_heap.front());
        std::pop_heap(stl_heap.begin(), stl_heap.end());
        stl_heap.pop_back();
    }
    stop = std::chrono::high_resolution_clock::now();
    std::cout << "std::make_heap from vector sorting took: "
              << std::fixed << std::setprecision(2)
              << std::chrono::duration_cast <std::chrono::microseconds> (stop - start).count() / 1000. << " milliseconds.\n";
   // char end_of_tests; std::cin >> end_of_tests;*/
   ///////////////
    //BTS tester
    int n = 1000;
    // A std :: pair can be used store the run times
    std::pair<double, double> times;
    
    // a vector of times can be used to store many trials
    std::vector<std::pair<double,double>> trials;
    
    //test searching in a random BST structure
    BinarySearchTree<int, std::string> bst;
    auto start1 = std::chrono::high_resolution_clock::now();  //auto start
    for (int i = 0; i < n; i++)
        bst.insert(std::rand() % n + 1, "a");   //,
    
    auto stop1 = std::chrono::high_resolution_clock::now();
    times.first = std::chrono::duration_cast
        <std::chrono::microseconds >(stop - start).count() ;
    
    //test searching in the worst-case BST structure
    BinarySearchTree<int, std::string> bst_inserted_bad;
    start1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        bst_inserted_bad.insert(i, "a"); }
    stop1 = std::chrono::high_resolution_clock::now();
    times.second = std::chrono::duration_cast
        <std::chrono::microseconds >(stop - start).count() ;
    // store this trial
    trials.push_back(times);
    //printing worst check order
    std::cout << "Inserting in random order" << times.first / 1000<< "milliseconds \n";
    std::cout << "n worst-case tree structure" << times.second / 1000<< "milliseconds\n";
    
    char end_of_tests; std::cin >> end_of_tests;
}
