#include <iostream>
#include <cstdlib> //random
#include <ctime> //czas do seeda funkcji rand()
#include <experimental/random>

int main(int argc,char **argv){
    if(argc != 3){
        std::cout<<"Nie poprawana liczba argumentow wejsciowych!\n";
        return 1;
    }

    int n = std::stoi(argv[1]);
    int max = std::stoi(argv[2]);

    srand(time(nullptr)); //ustawianie seeda funkcjhi rand
    for(int i = 0; i<n;i++)
    {
        std::cout<<std::experimental::randint(1,max)<<std::endl;
    }
    return 0;
}