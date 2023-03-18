#include "LinkedStack.hpp"
#include <iostream>

using namespace std;


Stack::Stack(int capacity) // Konstruktor. Argumentem jest rozmiar tablicy.
{
    (void)capacity; //Sprawia ze nie pojawia sie ostrzezenie o nie uzytej zmiennej capacity. (Nie jest uzyta bo interfejs jej wymaga)
    top = nullptr;  
    len = 0;
}
Stack::Stack() // Konstruktor bez argumentu
{
    top = nullptr;
    len = 0;
}
void Stack::push(int x) // Wstawia element na stos
{
    top = new Node(top,x);
    len++;
}
int Stack::pop() // Usuwa element ze stosu i zwraca jego wartość
{
    if(top != nullptr){
        int val;
        val = top->value;
        top = top->prev;
        len--;
        return val;
    }
    throw out_of_range("Stos jest pusty");

}

bool Stack::empty() // Sprawdza czy stos jest pusty
{
    if(top!=nullptr){
        return false;
    }
    return true;
}
