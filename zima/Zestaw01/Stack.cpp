#include <iostream>
#include <string>
#include <fstream>

#include "ArrayStack.hpp" //Wczytujemy stos z implementacja tablicowa

using namespace std;

int main()
{   
    int ile_polecen;
    cin >> ile_polecen; //Wczytuje pierwsza linijke = liczbe polecen = liczbe linijek

    Stack stos = Stack(ile_polecen); // inicjalizacja stosu o rozmiarze = ilosc polecen

    string polecenie;
    int liczba;
    for(int i = 0; i<ile_polecen;i++)
    {
        cin >> polecenie;
          
        if (polecenie == "A"){
            cin >> liczba;
            stos.push(liczba);
        }
        else if(polecenie == "D"){
            if(!stos.empty()){
                cout<<stos.pop()<<endl;}
            else{
                cout<<"EMPTY\n";}
        }
        else if(polecenie == "S")
        {
            cout<<stos.size()<<endl;
        }
        else
        {
            cout<< "Niepoprawne dane";
        }
    }

    return 0;
}