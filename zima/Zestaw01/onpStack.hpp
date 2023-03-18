
#ifndef ONP_STACK_H
#define ONP_STACK_H

/*
    Klasa stworzona na potrzeby klasy ONP.cpp, ostatecznie zastapiona przez
    TemplateStack.hpp ale zostawiam ja tu na wszelki wypadek
*/

class Stack {
    public:
        Stack(int capacity); // Konstruktor. Argumentem jest rozmiar tablicy.
        void push(char x); // Wstawia element na stos
        char pop(); // Usuwa element ze stosu i zwraca jego wartość
        int size(); // Zwraca liczbę elementów na stosie
        bool empty(); // Sprawdza czy stos jest pusty
        char top();
    private:
        int cap; //rozmiar tablicy
        char *stos;
        int end;
        void resize(int x);
};

#endif