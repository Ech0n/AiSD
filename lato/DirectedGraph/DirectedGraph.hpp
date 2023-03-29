#pragma once

#ifndef MDDGRAPH_H
#define MDDGRAPH_H
#include "Set.hpp"
class DirectedGraph{
    public:
        DirectedGraph(int numVert):vertex_count(numVert),vertexes(new Set<int>[numVert]){};    // inicjalizuje graf o numVert wierzchołkach
        void addEdge(int,int);     // dodaje krawędź pomiędzy wierzchołkami i i j
        void removeEdge(int, int);  // usuwa krawędź pomiędzy wierzchołkami i i j
        bool hasEdge(int, int);     // sprawdza czy krawędź pomiędzy wierzchołkami i i j istnieje
        Set<int> inConnections(int);  // zwraca wszystkie wierzchołki od których istnieją połączenia do wierzchołka i
        Set<int> outConnections(int); // zwraca wszystkie wierzchołki do których prowadzą krawędzie wychodzące z i
        Set<int> allConnections(int); // zwraca wszystkie wierzchołki które są połączone z i lub z którymi i jest połączony
        const int vertex_count;
    private:
        Set<int> *vertexes;
};

#endif