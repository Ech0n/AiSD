#include "InsertionSort.hpp"
#include <vector>
#include <iostream>

int main(){
    std::vector<int> v;
    int input;
    while( std::cin >> input){
        v.push_back(input);
    }

    sort<int>(v);

    for(const auto& i : v)
        std::cout << i << std::endl;

}