#include  <iostream>   //cin , cout
#include  <fstream>    //file  streams
#include  <iomanip>    // setprecision
#include  <iterator>   // isstream :: iterator
#include  <string>     //std:: string
#include  <vector>     //std:: vecto
#include  <numeric>    //std::  accumulate
#include  <algorithm> //std::sort
#include "DynArray.hpp"

int main()
{
 //**************** ]   *************************************
    std::cout  << "************ Part I**********\n";
    std::cout  << "Min , max  and  average  of a list of  numbers :\n";
    std::cout  << "****************************\n";
    std:: initializer_list <int> il{5,7,1,3,1024,19,29,-64, 0};
    DynArray<int> dyn_int_array(il.size(), il);

    //A2 Todo: Sort  the  DynArry <int> using  std::sort
    std::sort(dyn_int_array.begin(), dyn_int_array.end());
    //std::sort(il.begin(), il.end());
    
    //A2 Todo  get  max  and  min  using  DynArray  member  functions
    //begin,back    end, front
    std::cout  << "max      = " << dyn_int_array.back() << "\n";
    std::cout  << "min      = " << dyn_int_array.front() << "\n";
    //https://www.cplusplus.com/reference/numeric/accumulate/
    // il to dyn_int_array
    // 5 , devide by 2, 9?? to get average???
    std::cout  << "average = "<<std::accumulate(dyn_int_array.begin(), dyn_int_array.end(), 0)/ (double)dyn_int_array.size() << "\n";
    std::cout  << std::endl;
    //Part II
    std::cout  << "************ Part II **********\n";
    std::cout  << "Simple  Bioinformatics :\n";
    std::cout  << "*****************************\n";


    // open  file: sars_cov_2.txt  and  count  the  number  of DNA  base  nucleotides
    //
    std:: string  filename = "sars_cov_2.txt";
    std:: ifstream  ifs(filename);
    std:: istream_iterator <char> ifs_iter(ifs);
    std:: istream_iterator <char> ifs_end_iter;

    // count  number  of char’s in file
    int base_count = 0;
    for (; ifs_iter != ifs_end_iter; ifs_iter++)
    //{
        base_count++;
    //}
    //
    //  reset  ifstream  and  istream_iterator  to  beginning  of file
    ifs.clear(); ifs_iter = ifs.seekg(0, std::ios::beg);

    // copy  file  data to  bases DynArray
    DynArray <char> bases; bases.resize(base_count);
    std::copy(ifs_iter, ifs_end_iter, bases.begin());
//
    
    // close  the  file
    ifs.close();
    // A2 Todo: count of A’s, G’s T’s and C’s with  std:: count
    std::cout  << "(A)denine   count = "<< std::count(bases.begin(), bases.end(), 'A') << "\n";
    //std::cout  << "(A)denine   count = "<< std::count(bases.begin(), bases.end(), 'A') << "\n";
    std::cout  << "(G)uanine   count = "<< std::count(bases.begin(), bases.end(), 'G') << "\n";
    std::cout  << "(T)hymine   count = "<< std::count(bases.begin(), bases.end(), 'T') << "\n";
    std::cout  << "(C)ytosine  count = "<< std::count(bases.begin(), bases.end(), 'C') << "\n";
    std::cout  << std::endl;

//    A/T and G/C  devisoin ADD DOUBLE 
    //https://en.cppreference.com/w/cpp/algorithm/count
    std::cout  << std::fixed  << std::setprecision(2) << "A/T = " << (double)std::count(bases.begin(), bases.end(), 'A') / std::count(bases.begin(), bases.end(), 'T') << "\n";
    //std::cout  << std::fixed  << std::setprecision(2) << "A/T = " << std::count(bases.begin(), bases.end(), 'A') / std::count(bases.begin(), bases.end(), 'T') << "\n";
    std::cout  << std::fixed  << std::setprecision(2) << "G/C = " << (double)std::count(bases.begin(), bases.end(), 'G') / std::count(bases.begin(), bases.end(), 'C') << "\n";
    std::cout  << std::endl;std::cout  << "\n***** Tests  completed , enter  any key to exit *******\n";
    char s; std::cin  >> s;
       return  0;
//
//
    
}
