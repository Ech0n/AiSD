#ifndef LINKED_STACK_H
#define LINKED_STACK_H



class Stack {
    public:
        Stack(int capacity); // Konstruktor. Argumentem jest rozmiar tablicy.
        Stack(); // Konstruktor bez argumentu
        void push(int x); // Wstawia element x na stos
        int pop(); // Usuwa element ze stosu i zwraca jego wartość
        int size(){return len;}; // Zwraca liczbę elementów na stosie
        bool empty(); // Sprawdza czy stos jest pusty
        
    private:
        class Node{ //Prywatna klasa wykorzystywana jako pojedynczy element stosu
            public:
                Node *prev; //Poprzedni element
                int value;  //Wartosc elementu
                Node(Node *pre,int val){    //Konstruktor
                    prev = pre;
                    value = val;
                }
        };
        Node *top;  //Wskaznik na element na szczycie stosu
        int len;    //Dlugosc stosu
};



#endif