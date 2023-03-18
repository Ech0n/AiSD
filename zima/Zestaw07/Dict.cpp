#include <iostream>
#include <string>
#include "Dict.hpp"
#include <fstream>

int main(int argc,char **argv){
    if(argc!=2){
        throw std::invalid_argument("Podano nie prawidlowa ilosc argumentow");
    }
    std::ifstream wejscie(argv[1]);

    Dict<std::string, std::string> dict =  Dict<std::string, std::string>();

    std::string key ,value;
    while( wejscie >> key){
        wejscie >> value;
        //Polecenie zrozumialem w ten sposob ale nie zgadza sie z testem
        // dict.insert(std::pair<std::string,std::string>(key,value));
        dict[key] = value;
    }

    while( std::cin >> key){
        if(dict.find(key)){
            std::cout<< dict[key] <<std::endl;
        }else{
            std::cout<<"-"<<std::endl;
        }
    }

    return 0;
}