#include <iostream>
#include "PriorityQueue.hpp"

#include <queue> //Testowanie dzialania mojej implementacji przeciwko implementacji stl
#include <random>

#include <chrono> //Mierzenie czasu

#define LICZBA_TESTOW 200000
#define LICZBA_OPERACJI_POMIAROWYCH 2000000

int main(){
    PriorityQueue<int> que;
    //Populacja kolekjki
    que.insert(634,7);
    que.insert(234,18);
    que.insert(94,17);
    que.insert(235,9);
    que.insert(12,10);
    que.insert(99,13);
    que.insert(23,14);
    que.insert(325,1);
    que.insert(6,11);
    que.insert(654,6);
    que.insert(214,5);
    que.insert(632,2);
    que.insert(32,12);
    que.insert(423,8);
    que.insert(643,3);
    que.insert(2,4);
    que.insert(2,16);
    que.insert(10,15);
    //Oczekiwana kolejnosc zwracania elementow
    int oczekiwane_elementy[] = {234, 94, 2, 10, 23, 99, 32, 6, 12, 235, 423, 634, 654, 214, 2, 643, 632, 325};

    int i =0;
    while(que.size()>0){
        QE<int> element = que.extractmax();
        if( element.obj != oczekiwane_elementy[i] && element.priority-1 != i)
        {
            std::cout<<"Blad przy usuwaniu z kolejki!\nOczekiwano elementu: "<<oczekiwane_elementy[i]<<", a otrzymano: "<<element.obj<<std::endl;
            return 0;
        }
        i++;
    }
    std::cout<<"Test 1. ukonczony pomyslnie!\n";

    //Testowanie przeciwko stl
    std::priority_queue<int> stlque;
    for (int i = 0;i<LICZBA_TESTOW; i++){
        int temp = std::rand() %10000;
        que.insert(temp, temp);
        stlque.push(temp);
    }
    while(que.size()>0){
        if(int temp = que.extractmax().priority != stlque.top())
        {
            std::cout<<"Blad przy usuwaniu z kolejki!\nOczekiwano elementu: "<<temp<<", a otrzymano: "<<stlque.top()<<std::endl;
            return 0;
        }
        stlque.pop();
    }
    std::cout<<"Test 2. ukonczony pomyslnie!\n";

    //Porownanie szybkosci 
    auto timestart = std::chrono::high_resolution_clock::now();
    for (int i = 0;i<LICZBA_OPERACJI_POMIAROWYCH; i++){
        int temp = std::rand() %10000;
        que.insert(temp, temp);
    }
    while(que.size()>0){
        que.extractmax();
    }
    auto timeend = std::chrono::high_resolution_clock::now();
    std::cout<<"Czas wykonywania mojej implemetacji dla "<<LICZBA_OPERACJI_POMIAROWYCH<<" testow: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(timeend-timestart).count() << "ms"<<std::endl;
    //Pomiar kolejki stlowej
    timestart = std::chrono::high_resolution_clock::now();
    for (int i = 0;i<LICZBA_OPERACJI_POMIAROWYCH; i++){
        int temp = std::rand() %10000;
        stlque.push(temp);
    }
    while(stlque.size()>0){
        stlque.pop();
    }
    timeend = std::chrono::high_resolution_clock::now();
    std::cout<<"Czas wykonywania implemetacji stl dla "<<LICZBA_OPERACJI_POMIAROWYCH<<" testow: "
        << std::chrono::duration_cast<std::chrono::milliseconds>(timeend-timestart).count() << "ms"<<std::endl;
    
    return 0;
}