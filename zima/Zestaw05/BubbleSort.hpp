#ifndef BUBSORT_H
#define BUBSORT_H

#include <vector>
#include <algorithm>

template <class T>
void sort(std::vector<T>& v){
    bool swap = true;
    for(int i = 0;i<(int)v.size()-1 && swap;i++){
        swap = false;
        for(int j = i;j<(int)v.size();j++){
            if(v[i]>v[j]){
                std::swap(v[i],v[j]);
                swap = true;
            }
        }
    }
}

#endif