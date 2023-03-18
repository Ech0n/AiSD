#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>

#define DEFAULT_SIZE 10

#ifndef MDSET_H
#define MDSET_H

template <class T>
class Set{
    public: 
        Set(int reserved_size = DEFAULT_SIZE):_size(0),arr(new T[DEFAULT_SIZE]),_reserved_size(reserved_size){}
        void insert(T);
        bool isMember(T);
        void remove(T);
        void pop();
        int size();
        Set intersect(Set);
        Set difference(Set);
        Set unions(Set); //Nazwalem funkcje unions bo union jest juz zarezerwowanym slowem w cpp
        void print();
        std::string to_string();
    private:
        int _size;
        int *arr;
        int _reserved_size;
        void upsize();
        void downsize();
};

template<class T>
Set<T> Set<T>::intersect(Set<T> other){
    Set<T> new_set = Set<T>(_reserved_size);
    int i=0,j=0;
    while(i+j<size()+other.size()){
        if(arr[i]==other.arr[j]){
            new_set.insert(arr[i]);
            if(i<_size){i++;}
            if(j<other._size){j++;}
        }else if(arr[i]>other.arr[j]){
            if(j<other._size){j++;}
            else{return new_set;}
        }else{
            if(i<other._size){i++;}
            else{return new_set;}
        }
    }
    return new_set;
}

template<class T>
Set<T> Set<T>::difference(Set<T> other){
    Set<T> new_set = Set<T>(_reserved_size);
    Set<T> intersection_set = intersect(other);
    int i =0 ,j=0,k=0;
    while(k<intersection_set.size()){
        const T current_element = intersection_set.arr[k];
        while(arr[i]<current_element){
            new_set.insert(arr[i]);
            i++;
        }
        while(other.arr[j]<current_element)
        {
            new_set.insert(other.arr[j]);
            j++;
        }
        if(other.arr[j]==current_element)
        {
            j++;
        }
        if(arr[i]==current_element)
        {
            i++;
        }
        k++;
    }
    while(j<other.size()){
        new_set.insert(other.arr[j++]);
    }
    while(i<size()){
        new_set.insert(arr[i++]);
    }
    return new_set;
}

template <class T>
Set<T> Set<T>::unions(Set<T> other){
    Set<T> new_set = Set<T>(_reserved_size);
    std::copy(arr,arr+_size,new_set.arr);
    new_set._size = _size;
    for(int i = 0;i<other.size();i++){
        new_set.insert(other.arr[i]);
    }
    return new_set; 
}

template<class T>
int Set<T>::size(){
    return _size;
}

template<class T>
bool Set<T>::isMember(T x){
    return std::binary_search(arr,arr+_size,x);
}

template <class T>
void Set<T>::insert(T x){
    if(_size+2>_reserved_size){
        upsize();
    }
    int *indx = std::lower_bound(arr,arr+_size,x);
    if(*indx == x){
        return;
    }
    _size++;
    std::rotate(indx,arr+_size,arr+_size+1);
    *indx = x;
}

template <class T>
void Set<T>::remove(T x){
    int *indx = std::lower_bound(arr,arr+_size,x);
    if(indx-arr >= size()|| *indx != x){
        return;
    }
    std::rotate(indx,indx+1,arr+_size);
    _size--;
    if(_size*4<_reserved_size){
        downsize();
    }
}

template <class T>
void Set<T>::pop(){
    if(_size>0){
        _size--;
        if(_size*4<_reserved_size){
            downsize();
        }
    }
}

template <class T>
void Set<T>::upsize(){
    int new_size = _reserved_size*2;
    int *new_arr = new T[new_size];
    std::move(arr,arr+_size,new_arr);
    delete [] arr;
    arr = new_arr;
    _reserved_size = new_size;
}

template <class T>
void Set<T>::downsize(){
    int new_size = _reserved_size/2;
    int *new_arr = new T[new_size];
    std::move(arr,arr+_size,new_arr);
    delete [] arr;
    arr = new_arr;
    _reserved_size = new_size;
}
template<class T> 
void Set<T>::print(){
    for(int i = 0 ; i < _size;i++){
        std::cout<< arr[i]<<" ";
    }
    std::cout<<std::endl;
}

template<class T> 
std::string Set<T>::to_string(){
    std::stringstream ss;
    ss<<"( ";
    for(int i = 0 ; i < _size;i++){
        ss<< arr[i]<<" ";
    }
    ss<<")";
    return ss.str();
}

#endif