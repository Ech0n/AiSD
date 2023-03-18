#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H

#include <iostream>

class Queue{
    private:
        struct Node{ //Prywatna struktura wykorzystywana jako pojedynczy element kolejki
            
                Node *next; //Nastepny element
                int value;  //Wartosc elementu
                Node(int val){    //Konstruktor
                    value = val;
                }
        };
        Node *head;  //Wskaznik na poczatek kolejki
        Node *tail; //Wskaznik na ostatni element kolejki
        int len;    //Dlugosc kolejki 
    public:
        Queue(int capacity) // Konstruktor. Argumentem jest rozmiar tablicy.
        {
            (void)capacity; //Sprawia ze nie pojawia sie ostrzezenie o nie uzytej zmiennej capacity. (Nie jest uzyta bo interfejs jej wymaga)
            head = nullptr;  
            tail = nullptr;
            len = 0;
        }

        Queue()// Konstruktor bez argumentu
        {
            head = nullptr;
            tail = nullptr;
            len = 0;
        }

        void push(int x) // Wstawia element x na koniec kolejki
        {
            Node *temp = new Node(x);
            if(tail != nullptr){
                tail->next = temp;
            }else{
                head = temp;
            }
            tail = temp;
            len++;
        }

        int pop() // Usuwa element z kolejki i zwraca jego wartosc
        {
            if(head != nullptr){
                int val;
                val = head->value;
                head = head ->next;
                len--;
                if(head == nullptr){    //Jezeli usuniemy ostatni element to head bedzie = null
                    tail = nullptr;     // ale tail wciaz bedzie wskazywal na poprzedni element wiec nalezy go usunac
                }
                return val;
            }
            throw std::out_of_range("Stos jest pusty");

        }

        int size(){return len;}; // Zwraca liczbę elementów na w kolejce
        bool empty() // Sprawdza czy kolejka jest pusta
        {
            if(head!=nullptr){
                return false;
            }
            return true;
        }

};

#endif