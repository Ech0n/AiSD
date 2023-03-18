#ifndef DICT_H
#define DICT_H

#include <cmath>
#include "LinkedList.hpp"
#include <string>
#include <utility>

#define DICTSIZE 256
#define HASHCONSTP 31

class NoHashFunciton : public std::exception {
    public:
        char * what (){
            return (char*)"There is no hash function defined for given type!";
        }
};

template<class K>
unsigned int hash(K const &obj){
    throw NoHashFunciton();
}
template<>
unsigned int hash(std::string const &obj){
    unsigned sum = 0;
    int p = HASHCONSTP;
    int pow = 1;
    for(int i = 0; i<(int)obj.length();i++){
        sum=(sum+(obj[i]-'0'+1) * pow)%DICTSIZE;
        p = (pow*p)%DICTSIZE;
    }
    return sum;

}
template<>
unsigned int hash(int const &obj){
    return (obj*HASHCONSTP)%DICTSIZE ;
}


template<class K, class V>
class Dict {
    using Pair = std::pair<K, V>;
    public:
        Dict(); // Konstruktor
        void clear(); // Czyści słownik
        bool insert(const Pair& p); // Dodaje parę klucz-wartość do słownika
        bool find(const K& k); // Sprawdza czy słownik zawiera klucz
        V& operator[](const K& k); // Zwraca wartość dla klucza
        bool erase(const K& k); // Usuwa parę od danym kluczu
        int size() {return _size;} // Zwraca liczbę par
        bool empty() {return _size==0;}; // Sprawdza czy słownik jest pusty
        void buckets(); // Wypisuje informację o słowniku 
    private:
        List<Pair> *tablica;
        int _size;
};

template<class K, class V>
Dict<K,V>::Dict(){
    tablica = new List<Pair>[DICTSIZE]();
    _size = 0;
}


template<class K, class V>
bool Dict<K,V>::insert(const Pair& p){
    int hashed = hash<K>(p.first);
    if(!tablica[hashed].empty())
    {   
        for(auto i : tablica[hashed]){
            if(i.first == p.first){
                return false;
            }
    }}
    tablica[hashed].push_front(p);
    _size++;

    return true;
}

template<class K, class V>
bool Dict<K,V>::find(const K& key){
    int hashed = hash<K>(key);
    for(auto i : tablica[hashed]){
        if(i.first == key){
            return true;
        }
    }
    return false;
}

template<class K, class V>
V& Dict<K,V>::operator[](const K& k) // Zwraca wartość dla klucza
{
    int hashed = hash<K>(k);
    for(auto &i : tablica[hashed]){
        if(i.first == k){
            return i.second;
        }
    }
    V new_value;
    tablica[hashed].push_front(Pair(k,new_value));
    _size++;
    return (*(tablica[hashed].begin())).second;
}

template<class K, class V>
bool Dict<K,V>::erase(const K& k) // Usuwa parę od danym kluczu
{
    unsigned int hashed = hash<K>(k);
    typename List<Pair>::Iterator iter = tablica[hashed].begin();
    while(iter != tablica[hashed].end()){
        if((*iter).first==k){
            tablica[hashed].erase(iter);
            _size--;
            return true;
        }
        ++iter;
    }
    return false;
}


template<class K, class V>
void Dict<K,V>::buckets() //Informacje o slowniku
{
    int min = tablica[0].size();
    int max = 0;
    for(int i =0;i<DICTSIZE;i++){
        int s = tablica[i].size();
        if(s<min){
            min = s;
        }
        if(s>max){
            max = s;
        }
    }

    std::cout<<"#"<<_size<<" "<<DICTSIZE <<" "<<min<< " "<<max <<std::endl;
}



#endif