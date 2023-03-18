#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>
#include <cstdlib> //random
#include <ctime> //czas do seeda funkcji rand()
#include <experimental/random>
#include "SelectionSort.hpp"

int timesort(int n){
    std::vector<int> v;
    int input;

    srand(time(nullptr)); //ustawianie seeda funkcjhi rand
    for(int i = 0; i<n;i++)
    {
        // v.push_back(i);
        v.push_back(std::experimental::randint(1,n));
    }
    auto start = std::chrono::high_resolution_clock::now();
    sort<int>(v);
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end-start).count();
}

int main(){
    int values[] = {100,500,1000,5000,10000,50000,100000,500000};
    for(int i = 0;i<8;i++){
        std::cout<<values[i]<<": "<<timesort(values[i])<<"ms"<<std::endl;
    }
}