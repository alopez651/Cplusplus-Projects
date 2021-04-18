#include  <iostream> //io  stream
#include <fstream>     //file  streams
#include <iomanip>     // setprecision
#include  <iterator>   // isstream :: iterator
#include  <string>     //std:: string
#include  <vector>     //std:: vector
#include "IntArray.h"
#include  <numeric>    //std::  accumulate
#include  <algorithm> //std::sort
#include  <ctime>      //time
#include <utility>
#include  <random>     //srand ,rand
#include  <chrono>     // high_resolution  clock
//#include "IntArray.h"
#define  SAMPLE_SIZE  1000

int  main (){
    //https://en.cppreference.com/w/cpp/numeric/random/srand
    //std:: srand(std::time(0)); // use  current  time as seed  for
    std:: srand(std::time(nullptr));
    //random generator
    int  random_variable = std::rand ();
    //https://en.cppreference.com/w/cpp/numeric/random/rand
    //int  random_variable = std::rand ();
    /*std::cout << "Random value on [0 " << RAND_MAX << "]: "
                 << random_variable << '\n';*/
    IntArray  arr;//test  insert
    
    for (int i = 0; i < SAMPLE_SIZE; i++)
        arr.insert(std::rand() % 500 + 1);
    for (auto i : arr)
        std::cout  << i << " ";//test  remove  front
    int  rand_num = arr [0];
    std::cout  << "\nremove  front ="<<rand_num <<std::endl;
    
    arr.remove(rand_num );
    for (auto i : arr) std::cout  << i << " ";//test  remove  back
    rand_num = arr[arr.size() - 1];
    std::cout  << "\nremove  back=" << rand_num  << std::endl;
    arr.remove(rand_num );
    
    for (auto i : arr)std::cout  << i << " ";//test  remove  middle
    rand_num = arr[arr.size ()/2];
    std::cout  << "\nremove  middle=" << rand_num  << std::endl;
    arr.remove(rand_num );
    
    for (auto i : arr)std::cout  << i << " ";
    std::cout  << "\nrecursive  reverse ()"<< std::endl;
    arr.reverse ();
    for (auto i : arr)std::cout  << i << " ";
    std::cout  << std::endl;// example  sorting  algorithm  timing
    
    IntArray  unsorted(false);//time  bubble  sort
    for (int i = 0; i < SAMPLE_SIZE *1000; i++)unsorted.insert(std::rand() % 500 + 1);
    
    auto  start = std:: chrono :: high_resolution_clock ::now ();
    unsorted.sort ();
    
    auto  stop = std:: chrono :: high_resolution_clock ::now ();
    
    std::cout  << "An n^2  sorting  algorithm  took "
        << std::fixed  << std:: setprecision (2)
        << std:: chrono :: duration_cast <std:: chrono :: microseconds>
        (stop - start). count ()/1000.  << " milliseconds .\n";
    
    //time  quicksort  STL
    unsorted.clear ();
    for (int i = 0; i < SAMPLE_SIZE * 1000; i++)
        unsorted.insert(std::rand() % 500 + 1);
    
    
    start = std:: chrono :: high_resolution_clock ::now();
    std::sort(unsorted.begin(), unsorted.end ());
    stop = std:: chrono :: high_resolution_clock ::now ();
    
    std::cout  << "STL’s n log n sorting  algorithm  took "<< std::fixed <<std:: setprecision (2)<< std:: chrono :: duration_cast <std:: chrono :: microseconds >(stop -start). count ()/1000.  << " milliseconds .\n";
    
    std::cout  << "***** Tests  completed , enter  any key to exit *******\n";
    char  pause;
    std::cin  >> pause;
    return  0;
    
}
