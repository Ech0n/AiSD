#include "ArrayStack.hpp"
#include <iostream>

using namespace std;

Stack::Stack(int capacity) // Konstruktor. Argumentem jest rozmiar tablicy.
{
    cap = capacity;
    stos = new int[capacity];
    end = 0; //pozycja konca
}
void Stack::push(int x) // Wstawia element na stos
{
    if(end<cap){
        stos[end]=x;
        end++;
    }else
    {
        resize(10);
        stos[end]=x;
        end++;
    }
}
int Stack::pop() // Usuwa element ze stosu i zwraca jego wartość
{
    if(end>0){
        end--;
        int temp = stos[end];
        stos[end]=0;
        return temp;
    }else
    {
        throw out_of_range("Stos jest pusty");
    }
}
int Stack::size() // Zwraca liczbę elementów na stosie
{
    return end;
}
bool Stack::empty() // Sprawdza czy stos jest pusty
{
    if(end>0){
        return false;
    }
    return true;
}

void Stack::resize(int x){
    int *new_stos = new int[cap+x];
    for(int i = 0;i<cap;i++){
        new_stos[i] = stos[i];
    }
    stos = new_stos;
    cap = cap+x;
}
