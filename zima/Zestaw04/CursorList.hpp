#ifndef CURLIST_H
#define CURLIST_H

#include <iostream>

#define ARR_SIZE 32768 // 2^15

template <class T>
class List {
    private:
        struct Node { // Zagnieżdżona klasa węzła
            T x; // Element przechowywany przez węzeł listy
            int next; // Indeks kolejnego węzła
        };
        int spare; //nastepny wolny wezel
        int length;
        int front, back;
        Node *tablica; // Tablica węzłów

    public:
        struct Iterator{
            Node* tab;
            int pos;
            Iterator(int n, Node *tablica){
                pos = n;
                tab = tablica;
            }
            T& operator*(){ //Operator: *
                return tab[pos].x;}  
            T* operator->(){  &(tab[pos].x) ;} 
            bool operator==(const Iterator &prawy){ // Operator porownania ==
                return this->pos == prawy.pos;}
            bool operator!=(const Iterator &prawy){ //Operator nie rownosci !=
                return !(this->pos == prawy.pos);} 
            Iterator &operator++(){ //operator inkrementacji (prefix)
                if( pos != -1){
                    pos = tab[pos].next;
                    
                }
                return *this;  
            }
                
        };
        List();
        void push_front(T x); // Dołącza element na początek listy
        T pop_front(); // Usuwa i zwraca element z początku listy
        void push_back(T x); // Dołącza element na koniec listy
        T pop_back(); // Usuwa i zwraca element z końca listy
        int size(); // Zwraca liczbę elementów w liście
        bool empty(); // Zwraca true gdy lista jest pusta
        void clear(); // Czyści listę
        Iterator find(T x); // Zwraca pozycję pierwszego elementu o wartości x
        Iterator erase(Iterator i); // Usuwa i zwraca element na pozycji i
        Iterator insert(Iterator i, T x); // Wstawia element x przed pozycję i
        int remove(T x); // Usuwa wystąpienia x i zwraca ich liczbę
        Iterator begin(){return Iterator(front,tablica);}
        Iterator end(){return Iterator(-1, tablica);}   //Iterator wskazujacy na miejsce za ostatnim elementem
        Iterator last(){return Iterator(back, tablica);}  //Iterator wskazujacy na ostatni element

};

template<class T>
List<T>::List(){
    tablica = new List<T>::Node[ARR_SIZE];
    for(int i =0;i<ARR_SIZE-1;i++){
        tablica[i].next = i+1;
    }
    tablica[ARR_SIZE-1].next = -1;
    spare = 0;
    length= 0;
    front = -1;
    back = -1;
}

template<class T>
void List<T>::push_back(T x){
    if(length <= ARR_SIZE){
        int new_indx = spare;
        spare = tablica[spare].next;

        tablica[new_indx].next = -1;
        tablica[back].next = new_indx;
        back = new_indx;
        tablica[back].x = x;
        if(front == -1){
            front = back;
        }
        length++;
    }else{
        throw std::out_of_range("Nie mozna wykonac operacji insert na pelnej tablicy!");
    }
}


template<class T>
void List<T>::push_front(T x){
    if(length <= ARR_SIZE){
        int new_indx = spare;
        spare = tablica[spare].next;

        tablica[new_indx].next = front;
        front = new_indx;
        tablica[front].x = x;
        if( back == -1){
            back = front;
        }
        length++;
    }else{
        throw std::out_of_range("Nie mozna wykonac operacji insert na pelnej tablicy!");
    }
}

template<class T>
T List<T>::pop_front(){
    if(!empty()){
        T wynik = tablica[front].x;
        int new_front = tablica[front].next;
        tablica[front].next = spare;
        spare = front;        
        if(front==back){
            front = -1;
            back = -1;
        }else{
            front = new_front;
        }
        length--;
        return wynik; 
    }
    throw std::out_of_range("Nie mozna wykonac operacji pop_front na pustej tablicy!");
}

template<class T>
T List<T>::pop_back(){
    if(empty()){
        throw std::out_of_range("Nie mozna wykonac operacji pop_front na pustej tablicy!");
    }
    if(back==front){
        return pop_front();
    }

    T wynik = tablica[back].x;
    Iterator prev = end();
    
    for(Iterator it = begin();it!=end();++it){
        if(it==last()){
            tablica[back].next = spare;
            spare = back;
            back = prev.pos;
            tablica[back].next = -1;
            length--;
            return wynik;
        }
        prev = it;
    }
    return -1;    
}

template<class T>
typename List<T>::Iterator List<T>::insert(Iterator i, T x)// Wstawia element x przed pozycję i
{
    if(i == end()){push_back(x); return last();}
    if(i == begin()){push_front(x); return begin();}
    int new_node = spare;
    spare = tablica[spare].next;
    tablica[new_node].x = x;
    Iterator prev = begin();
    for(Iterator it = begin();it != end();++it){
        if(it == i){
            tablica[prev.pos].next = new_node;
            tablica[new_node].next = it.pos;
            length++;
            return ++prev;
        }
        prev = it;
    }
    return end();
}
template<class T>
typename List<T>::Iterator List<T>::find(T x){
    for(Iterator it = begin();it!=end();++it){
        if(*it==x){
            return it;
        }
    }
    return end();
}

template<class T>
typename List<T>::Iterator List<T>::erase(Iterator i){
    if(i.pos == -1){throw std::out_of_range("Erase Iterator out of range!");}
    if(!empty()){
        if(i == begin()){ 
            pop_front();
            return begin();
        }
        if(i == last()){
            pop_back();
            return end();
        }

        Iterator prev = begin();
        for(Iterator it = begin();it != end();++it){
            if(it == i){
                Iterator rets = it;
                ++rets;
                int next = tablica[it.pos].next;
                tablica[it.pos].next = spare;
                spare = it.pos;
                tablica[prev.pos].next = next;
                length--;
                return rets;
            }
            prev = it;
        }
        throw std::out_of_range("Erase Iterator out of range!");
    }else{
        throw std::out_of_range("Nie mozna wykonac operacji erase na pustej tablicy!");
    }
}

template<class T>
int List<T>::size() // Zwraca liczbę elementów w liście
{
    return length;
}

template<class T>
bool List<T>::empty() // Zwraca true gdy lista jest pusta
{
    return (length==0);
}

template<class T>
void List<T>::clear()
{
    int temporary_fronts;
    while(front!=-1)
    {
        temporary_fronts = tablica[front].next;
        tablica[front].next = spare;
        spare = front;
        front = temporary_fronts;
    }
    length = 0;
    front = -1;
    back = -1;
}

template<class T>
int List<T>::remove(T x){
    int ile = 0;
    for(Iterator it = begin();it != end();++it){
        while( *it == x ){
            it = erase(it);
            ile++;
        }
    }
    return ile;
}

#endif