#ifndef CURLIST_H
#define CURLIST_H

#include <iostream>

#define ARR_SIZE 32768 // 2^15

template <class T>
class List {
    public:
        List();
        void push_front(T x); // Dołącza element na początek listy
        T pop_front(); // Usuwa i zwraca element z początku listy
        void push_back(T x); // Dołącza element na koniec listy
        T pop_back(); // Usuwa i zwraca element z końca listy
        int size(); // Zwraca liczbę elementów w liście
        bool empty(); // Zwraca true gdy lista jest pusta
        void clear(); // Czyści listę
        int find(T x); // Zwraca pozycję pierwszego elementu o wartości x
        T erase(int i); // Usuwa i zwraca element na pozycji i
        void insert(int i, T x); // Wstawia element x przed pozycję i
        int remove(T x); // Usuwa wystąpienia x i zwraca ich liczbę
    private:
        T *tablica;
        int front, back;
        int mask(int index){
            return index & (ARR_SIZE-1);
        }        
        void shiftleft(int );
        void shiftright(int );
        void erase_shiftleft(int );
        void erase_shiftright(int );

};

template<class T>
List<T>::List(){
    tablica = new T[ARR_SIZE];
    front = 0;
    back = 0;
}

template<class T>
void List<T>::push_back(T x){
    if(size() <= ARR_SIZE){
        tablica[mask(back++)] = x;
    }else{
        throw std::out_of_range("Nie mozna wykonac operacji insert na pelnej tablicy!");
    }
}

template<class T>
void List<T>::push_front(T x){
    if(size() <= ARR_SIZE){
        tablica[mask(--front)] = x;
    }else{
        throw std::out_of_range("Nie mozna wykonac operacji insert na pelnej tablicy!");
    }
}

template<class T>
T List<T>::pop_front(){
    if(!empty()){
        return tablica[mask(front++)]; 
    }
    throw std::out_of_range("Nie mozna wykonac operacji pop_front na pustej tablicy!");
}

template<class T>
T List<T>::pop_back(){
    if(!empty()){
        return tablica[mask(--back)]; 
    }
    throw std::out_of_range("Nie mozna wykonac operacji pop_back na pustej tablicy!");
    
}


template<class T>
void List<T>::shiftleft(int i){
    int n = front;
    while(n<(i+front)){
        tablica[mask(n-1)] = tablica[mask(n)];
        n++;
    }
    front--;
}
template<class T>
void List<T>::shiftright(int i){
    int n = back+1;
    while(n>=(i+front)){
        tablica[mask(n)] = tablica[mask(n-1)];
        n--;
    }
    back++;
}

template<class T>
void List<T>::insert(int i,T x){
    if(i>size() || i<0){return 
        throw std::out_of_range("Insert: Podano nie poprawny index");
    }
    if(i<size()/2){shiftleft(i);}
    else{shiftright(i);}
    tablica[mask(i+front)] = x;
}

template<class T>
int List<T>::find(T x){
    for(int i = front;i<back;i++){
        if( tablica[mask(i)] == x){
            return i-front;
        }
    }
    return -1;
}

template<class T>
void List<T>::erase_shiftright(int i)
{
    int j = front;
    i += front;
    while(i>j){
        tablica[mask(i)] = tablica[mask(i-1)];
        i--;
    }
    front++;
    
}

template<class T>
void List<T>::erase_shiftleft(int i)
{
    int j = back;
    i += front;
    while(i<j){
        tablica[mask(i)] = tablica[mask(i+1)];
        i++;
    }
    back--;

}

template<class T>
T List<T>::erase(int i){
    if(size() == 0){
        throw std::out_of_range("Nie mozna usunac w pustej tablicy!");
    }
    if(i>=size() || i<0){
        throw std::out_of_range("Erase index out of range!");
    }else{
        T ret = tablica[mask(front+i)];
        if(i<size()/2){erase_shiftright(i);}
        else{erase_shiftleft(i);}
        return ret;
    }
}

template<class T>
int List<T>::size() // Zwraca liczbę elementów w liście
{
    return back-front;
}

template<class T>
bool List<T>::empty() // Zwraca true gdy lista jest pusta
{
    return (size()==0);
}

template<class T>
void List<T>::clear()
{
    front = 0;
    back = 0;
}

template<class T>
int List<T>::remove(T x){
    int counter = 0;
    for(int i =0; i<size();i++){
        std::cout<<"E: "<<tablica[mask(i+front)]<<"; ";
        if(tablica[mask(i+front)]==x){
            erase(i);
            i--;
            counter++;
        }
    }
    return counter;
}

#endif