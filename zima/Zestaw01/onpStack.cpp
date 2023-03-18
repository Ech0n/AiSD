#include "onpStack.hpp"
#include <iostream>

using namespace std;

Stack::Stack(int capacity) // Konstruktor. Argumentem jest rozmiar tablicy.
{
    cap = capacity;
    stos = new char[capacity];
    end = 0; //pozycja konca
}
char Stack::top(){
    return stos[end-1];
}
void Stack::push(char x) // Wstawia element na stos
{
    if(end<cap){    //Sprawdza czy element miesci sie na stosie
        stos[end]=x;
        end++;
    }else
    {
        //Powiekszenie stosu o 10 zeby byl zapas
        resize(10);
        stos[end]=x;
        end++;
    }
}
char Stack::pop() // Usuwa element ze stosu i zwraca jego wartość
{
    if(end>0){
        end--;
        int temp = stos[end];
        stos[end]=0;
        return temp;
    }else
    {
        cout<<"Stos jest pusty"<<endl;
        return 0;
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
    char *new_stos = new char[cap+x];   //Tworzenie nowej tablicy
    for(int i = 0;i<cap;i++){   //Kopiowanie elementuow ze starej tablicy
        new_stos[i] = stos[i];  
    }
    stos = new_stos;    //Podmiana tablic
    cap = cap+x;
    
}
