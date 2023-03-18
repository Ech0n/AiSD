#include <iostream>
#include <string>
#include <cstdlib> //random
#include <ctime> //czas do seeda funkcji rand()
#include <experimental/random>
#include <fstream> //zapisywanie do pliku

#include "LinkedStack.hpp"

using namespace std;
 

int main()
{   
    ofstream outfile("dane.txt");   //plik wyjsciowy
    srand(time(nullptr)); //ustawianie seeda funkcjhi rand
    int number_of_inputs = experimental::randint(1,1000000);    //liczba wejsc
    outfile << number_of_inputs<<endl;
    for(int i = 0; i<number_of_inputs;i++)
    {
        //pick random operation
        switch(experimental::randint(1,3)){ //wybor jednego z 3 polecen
            case 1:
                outfile<<"A "<<experimental::randint(0,1000000)<<endl;  //losowa liczba
            break;
            case 2:
                outfile<<"D"<<endl;
            break;
            case 3:
                outfile<<"S"<<endl;
            break;
        }
    }
    outfile.close();    //zamkniecie pliku wyjsciowego
    return 0;
}