#include <iostream>
#include "Points.hpp"

int main(int argc,char **argv){
    int wymiar;
    Points punkty = Points(0);
    if(argc == 2){
        wymiar = punkty.load_from_file(argv[1]);
    }else{
        std::cout<<"Podaj wymiar przestrzeni:\n";
        std::cin >> wymiar;
        punkty = Points(wymiar);
    }
    int ile_polecen;
    std::cout<<"Podaj ilosc polecen:\n";
    std::cin >> ile_polecen;
    float liczba;
    char polecenie = ' ';
    for(int i = 0; i<ile_polecen;i++)
    {   std::cin >> polecenie;
        if(polecenie == 'R')
        {
            Wektor x = Wektor(wymiar);
            for(int j = 0;j<wymiar;j++){
                std::cin >> liczba;
                x[j] = liczba;
            }
            punkty.insert(x);
        }else if(polecenie == 'N'){
            Wektor x = Wektor(wymiar);
            for(int j = 0;j<wymiar;j++){
                std::cin >> liczba;
                x[j] = liczba;
            }
            std::cout << (punkty.find_nearest(x)).to_string()<<std::endl;
        }else if(polecenie == 'P'){
            punkty.print();
        }else if(polecenie == 'S'){
            std::string filename ="";
            std::cin >> filename;
            punkty.save_to_file(filename);
        }
        else if(polecenie == 'H'){
            std::cout<<punkty.size()<<std::endl;
        }
        else if(polecenie == 'D'){
            std::cout<<punkty.get_dimension()<<std::endl;
        }
        else{
            std::cout<<"Niezdefiniowane polecenie!"<<std::endl;
        }
    }

    

    return 0;
}