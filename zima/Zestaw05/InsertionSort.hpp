#ifndef INSSORT_H
#define INSSORT_H

#include <vector>
#include <algorithm>

template <class T>
void sort(std::vector<T>& v){
    for(int i = 1;i<(int)v.size();i++){
        int j = i;
        T x = v[i];
        while(  x<v[j-1]){
            v[j] = v[j-1];
            j--;
        }
        v[j] = x;        
    }
}

#endif