#include <vector>
#include <iostream>
#include <algorithm>
#include <chrono>

template <class T>
void sort(std::vector<T>& v){
    // n = rozmiar wektora
    int cmps = 0, assignments = 0;
    cmps++;
    for(int i = 1;i<(int)v.size();i++){ 
        cmps++;
        int j = i;
        T x = v[i];
        assignments++;
        cmps++;
        while(  x<v[j-1]){  
            cmps++;
            v[j] = v[j-1];
            assignments++;
            j--;
        }
        v[j] = x;       
        assignments++; 
    }

    std::cout<<"    porownania: "<<cmps<<", przypisania: "<<assignments<<std::endl;

}

int main(){
    std::vector<int> v;
    int input;
    std::cout<<"Liczby operacji dla insertion sort:\n";
    std::cout<<"Sortowanie dla danych losowych (zlozonosc srednia), Oczekiwana zlozonosc: O(n^2):\n";
    //Dane losowe
    while( std::cin >> input){
        v.push_back(input);
    }
    sort<int>(v);

    //dane posortowane
    std::cout<<"Sortowanie dla danych posortowanych (zlozonosc optymistyczna), Oczekiwana zlozonosc: O(n):\n";
    sort<int>(v);

    std::reverse(v.begin(),v.end());

    std::cout<<"Sortowanie dla danych odwrotnie posortowanych (zlozonosc pesymistyczna), Oczekiwana zlozonosc: O(n^2):\n";
    sort<int>(v);

}