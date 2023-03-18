#include <iostream>
#include "Set.hpp"

void test(int nr_testu,Set<int> zbior,std::string oczekiwana_wartosc,int oczekiwana_wielkosc){
    if(zbior.to_string()!=oczekiwana_wartosc || zbior.size() != oczekiwana_wielkosc){
        std::cout<<"Blad w tescie nr "<<nr_testu<<" .\n"<<zbior.to_string()<<" !=\n"<<oczekiwana_wartosc<<std::endl;
        exit(0);
    }
    std::cout<<"Test nr:"<<nr_testu<<" zdanny!\n";
}

int main(){
    Set<int> zbior = Set<int>();

    //Tworzymy zbior 5 9 11 20
    //test 1.
    zbior.insert(11);
    zbior.insert(20);
    zbior.insert(5);
    zbior.insert(9);
    test(1,zbior,"( 5 9 11 20 )",4);
    //test 2
    zbior.pop();
    zbior.remove(20);
    zbior.remove(9);
    zbior.insert(221);
    zbior.insert(-1);
    zbior.insert(18);
    zbior.insert(7);
    zbior.remove(9);
    zbior.insert(113);
    zbior.insert(18);
    test(2,zbior,"( -1 5 7 11 18 113 221 )",7);
    //test 3
    Set<int> dodatkowy_zbior = Set<int>();
    dodatkowy_zbior.insert(9);
    dodatkowy_zbior.insert(2);
    dodatkowy_zbior.insert( 11);
    dodatkowy_zbior.insert( 20);
    dodatkowy_zbior.insert( 18);
    dodatkowy_zbior.insert( 31);
    dodatkowy_zbior.insert( 5);
    dodatkowy_zbior.insert( 113);
    dodatkowy_zbior.insert( 50);
    dodatkowy_zbior.insert( 80);
    dodatkowy_zbior.insert( 76);
    //test 4 i 5 i 6
    test(3,zbior.unions(dodatkowy_zbior),"( -1 2 5 7 9 11 18 20 31 50 76 80 113 221 )",14);
    test(4,zbior.intersect(dodatkowy_zbior),"( 5 11 18 113 )",4);
    test(5,zbior.difference(dodatkowy_zbior),"( -1 2 7 9 20 31 50 76 80 221 )",10);


    return 0;
}