#include <iostream>
#include <vector>

#include "LinkedQueue.hpp"

//Funkcja znajdujaca najwieksza liczbe w vectorze
int max(std::vector<int> &v){
    int m = v[0];
    for(int i = 0;i<(int)v.size();i++){
        if(v[i]>m){
            m = v[i];
        }
    }
    return m;
}

//Funkcja sortujaca
void radix(std::vector<int>& v){
    Queue kolejki[10]; 

    int maks = max(v);  //Najwieksza liczba z vektora
    int digit,num;      //zmienne tymczasowo przechowujaca liczbe oraz wybrana cyfre z tej liczby
    for(int i = 1;i<maks;i*=10){  // i = kolejne potegi 10 poki i < najwieksza liczba
        //Wloz liczby z vectora do kolejek
        while(!v.empty())
        {
            num = v[0];
            digit = ((num%(i*10)/i));   //Uzyskiwanie pozadanej cyfry
            kolejki[digit].push(num);   //Wsadzanie liczby do poprawnej kolejki na podstawie cyfry
            v.erase(v.begin());         
        }

        for(int k = 0;k<10;k++){// k = numer kolejki do oproznienia
            while(!kolejki[k].empty()){
                num = kolejki[k].pop(); 
                v.push_back(num);
            }
        }
    }
}

int main(){

    int x;  //Zmienna przechowujaca liczbe z wejsia
    std::vector<int> v; //Wektor w ktorym przechowane beda liczby
    while(std::cin >> x)
        v.push_back(x);

    radix(v);   //Sortowanie

    //Wypisanie wyniku
    for(const auto& i : v)
        std::cout << i << std::endl;

    return 0;
}