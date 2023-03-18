
#ifndef ARRQUE_H
#define ARRQUE_H

#include <iostream>

class Queue {

    private:
        int index_read,index_write; //Indexy wskazujace na poczatek i koniec kolejki
        int reserved_size;  //Zarezerwowany rozmiar tablicy
        int *kolejka; //Wskaznik na tablice obslugujaca kolejke
        /* Maskowanie indexow*/
        int mask(int value){ return value%reserved_size;  }

    public:
        Queue(int capacity) // Konstruktor. Argumentem jest rozmiar tablicy.
        {
            index_read = 0; 
            index_write = 0;
            reserved_size = capacity;
            kolejka = new int[capacity];
        }
        void push(int x){   //Funkcja dodaje nowy element do kolejki
            if(reserved_size!=size()){
                kolejka[mask(index_write++)] = x;
            }else{
                throw std::out_of_range("Nie mozna wykonac operacji push na pelnej kolekce");
            }
        }
        int pop(){  //Funkcja usuwa najstarszy element z kolejki
            if(!empty()){
                int temp = kolejka[mask(index_read)];
                kolejka[mask(index_read)] = 0;
                index_read++;
                return temp;
            }else{
                throw std::out_of_range("Nie mozna wykonac operacji pop na pustej tablicy");
            }
        }
        int size(){ //Funkcja zwraca ilosc elementow w kolejce
            return index_write-index_read;
        }
        bool empty(){   //Funkcja zwraca true jezeli kolejka jest pusta
            return index_read==index_write;
        }

};

#endif