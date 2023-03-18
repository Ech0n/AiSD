#include <iostream>
#include <string>
#include <cstdlib> //random
#include <ctime> //czas do seeda funkcji rand()
#include <experimental/random>
#include <fstream> //zapisywanie do pliku

using namespace std;
 

int main()
{   
    ofstream outfile("dane.txt");   //plik wyjsciowy
    srand(time(nullptr)); //ustawianie seeda funkcjhi rand
    int number_of_inputs = experimental::randint(1,1000);    //liczba wejsc
    outfile << number_of_inputs<<endl;
    for(int i = 0; i<number_of_inputs;i++)
    {
        //pick random operation
        switch(experimental::randint(1,6)){ //wybor jednego z 6 polecen
            case 1:
                outfile<<"F "<<experimental::randint(0,1000)<<endl; 
            break;
            case 2:
                outfile<<"B "<<experimental::randint(0,1000)<<endl; 
            break;
            case 3:
                outfile<<"R "<<experimental::randint(0,1000)<<" "<<experimental::randint(0,1000)<<endl;  //losowa liczba
            break;
            case 4:
                outfile<<"b"<<endl;
            break;
            case 5:
                outfile<<"f"<<endl;
            break;
            case 6:
                outfile<<"S"<<endl;
            break;
        }
    }
    outfile.close();    //zamkniecie pliku wyjsciowego
    return 0;
}