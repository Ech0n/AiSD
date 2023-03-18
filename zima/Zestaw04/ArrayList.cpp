#include <iostream>
#include "ArrayList.hpp"
#include <string>
#include <fstream>
#include <cmath>

int main(){
    List<short> L = List<short>();

    int ile_polecen;
    std::cin >> ile_polecen; //Wczytuje pierwsza linijke = liczbe polecen = liczbe linijek
    std::string polecenie;  //tymczasowa zmienna przechowujaca polecenie otrzymane na wejsicu
    short liczba, drugaliczba;             //tymczasowa zmienna przechowujaca liczby do polecen B F R
    for(int i = 0; i<ile_polecen;i++)
    {
        std::cin >> polecenie;
        if (polecenie == "F"){  //Polecenie 'F', dodaje liczbe na poczatek listy
            
            std::cin >> liczba;
            L.push_front(liczba);
        }
        else if (polecenie == "B"){  //Polecenie 'B', dodaje liczbe na koniec listy
            
            std::cin >> liczba;
            L.push_back(liczba);
        }
        else if(polecenie == "f"){  //Polecenie 'f', usuwa pierwszy element listy
            if(!L.empty())
            {
                std::cout<<L.pop_front()<<std::endl;
            }
            else{
                std::cout<<"EMPTY\n";
                }
        }
        else if(polecenie == "b"){  //Polecenie 'b', usuwa ostatni element listy
            if(!L.empty()){
                std::cout<<L.pop_back()<<std::endl;
            }
            else{
                std::cout<<"EMPTY\n";}
        }
        else if(polecenie == "S")   //polecenie 'S', wyswietla rozmiar listy
        {
            std::cout<<L.size()<< std::endl;
        }
        else if(polecenie == "R")   //polecenie 'R', Jezeli pierwsza wczytana liczba jest w liscie (wypisanie TRUE wpp FALSE),
        {                           //to jej pierwsze wystapienie zostaje zamienione na druga liczbe
            std::cin>>liczba >> drugaliczba;
            int indx = L.find(liczba);            
            if(indx == -1){        //Liczba nie znajduje sie na liscie
                std::cout<<"FALSE\n";
            }else{      
                //Liczba znajduje sie na liscie
                L.erase(indx);   //Usuwamy liczbe   
                L.insert(indx,drugaliczba);   //W miejsce poprzedniej liczby insertujemy nowa
                
                std::cout<<"TRUE\n";
            }
        }
        else
        {
            std::cout<< "Niepoprawne dane";
        }
    }


    return 0;
}
