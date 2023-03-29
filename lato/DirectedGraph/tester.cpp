#include <iostream>
#include "BFS.hpp"


int main(){
    DirectedGraph graph = DirectedGraph(14);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,0);
    graph.addEdge(2,13);
    graph.addEdge(2,5);
    graph.addEdge(2,4);
    graph.addEdge(3,4);
    graph.addEdge(3,1);
    graph.addEdge(3,8);
    graph.addEdge(3,7);
    graph.addEdge(8,9);
    graph.addEdge(9,12);
    graph.addEdge(9,10);
    graph.addEdge(10,11);
    graph.addEdge(10,7);
    graph.addEdge(7,10);
    graph.addEdge(4,7);
    graph.addEdge(4,3);
    graph.addEdge(4,6);
    graph.addEdge(2,5);
    graph.addEdge(5,2);
    graph.addEdge(6,5);
    graph.addEdge(6,4);
    graph.addEdge(5,6);

    int* arr = BFS(graph,0);
    for(int i =0;i<graph.vertex_count;i++){
        std::cout<< arr[i]<<" ";
    }
    std::cout<<std::endl;
    return 0;
}