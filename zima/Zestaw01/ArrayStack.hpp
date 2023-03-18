
#ifndef STACK_H
#define STACK_H

class Stack {
    public:
        Stack(int capacity); // Konstruktor. Argumentem jest rozmiar tablicy.
        void push(int x); // Wstawia element na stos
        int pop(); // Usuwa element ze stosu i zwraca jego wartość
        int size(); // Zwraca liczbę elementów na stosie
        bool empty(); // Sprawdza czy stos jest pusty
    private:
        int cap; //Zarezerwowany rozmiar tablicy
        int *stos;  //Wskaznik na tablice obslugujaca stos
        int end;    //Pozycja ostatniego elementu tablicy
        void resize(int x); //Funckja zmienijaca zarezerwowany rozmiar tablicy w efekci stos ten jest dynamiczny
};

#endif