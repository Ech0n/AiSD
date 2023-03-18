#include <iostream>
#include <string>
#include <fstream>
#include <cmath>

#include "ArrayQueue.hpp" 


int main()
{   
    int ile_polecen;
    std::cin >> ile_polecen; //Wczytuje pierwsza linijke = liczbe polecen = liczbe linijek
    int rozmiar = pow(2, ceil(log2(ile_polecen))); // Znajdujemy najblizsza potege 2 poniewaz rozmiar kolejki pownien byc potega liczby 2
    Queue kolejka = Queue(rozmiar); // inicjalizacja stosu o rozmiarze = ilosc polecen

    std::string polecenie;  //tymczasowa zmienna przechowujaca polecenie otrzymane na wejsicu
    int liczba;             //tymczasowa zmienna przechowujaca liczbe w przypadku polecenia 'A'
    for(int i = 0; i<ile_polecen;i++)
    {
        std::cin >> polecenie;
        if (polecenie == "A"){  //Polecenie 'A', pushuje liczbe do kolejki
            
            std::cin >> liczba;
            if(kolejka.size()<=rozmiar)
            kolejka.push(liczba);
        }
        else if(polecenie == "D"){  //Polecenie 'D', zdejmuje element z kolejki i wypisuje go na wyjsciu
            if(!kolejka.empty()){
                std::cout<<kolejka.pop()<< std::endl;}
            else{
                std::cout<<"EMPTY\n";}
        }
        else if(polecenie == "S")   //polecenie 'S', wyswietla rozmiar kolejki
        {
            std::cout<<kolejka.size()<< std::endl;
        }
        else
        {
            std::cout<< "Niepoprawne dane";
        }
    }

    return 0;
}