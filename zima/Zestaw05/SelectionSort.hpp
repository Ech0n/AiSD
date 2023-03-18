#ifndef SELSORT_H
#define SELSORT_H

#include <vector>
#include <algorithm> //min_element, iter_swap
#include <iostream>

template <class T>
void sort(std::vector<T>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        //Najmniejsza wartosc znaleziona pomiedzy iteratorem it i koncem listy
        auto minelement = std::min_element(it,v.end());
        std::iter_swap(it,minelement);
    }
}

#endif