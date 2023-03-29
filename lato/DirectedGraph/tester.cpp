#include <iostream>
#include "BFS.hpp"


int main(){
    DirectedGraph graph = DirectedGraph(15);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(0,3);
    graph.addEdge(1,0);
    graph.addEdge(1,14);
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
    graph.addEdge(5,2);
    graph.addEdge(6,5);
    graph.addEdge(6,4);
    graph.addEdge(5,6);
    graph.addEdge(14,2);
    graph.addEdge(13,0);


    int* arr = BFS(graph,0);

    int expected_results[] = {0,1,1,1,2,2,3,2,2,3,3,4,4,2,2};

    for(int i =0;i<graph.vertex_count;i++){
        // std::cout<< arr[i]<<" ";
        if(expected_results[i] != arr[i]){
            std::cout<< "Shortest path from 0 to "<<i<<" is expected to be "<<expected_results[i]<<", not "<<arr[i]<<std::endl;
            return 1;
        }
    }
    //test 2
    int test2[10] = {0,1,14,2,3,4,8,13,2,5};
    bool expected_test2[9] = {1,1,1,0,1,0,0,0,1};
    for(int i =0;i<9;i++){
        if(graph.hasEdge(test2[i],test2[i+1]) != expected_test2[i]){
            std::string temp = (expected_test2[i]) ? " " : "not " ;
            std::cout<< "graph shouuld"<< temp <<"have an edge from "<<test2[i]<<" to "<<test2[i+1]<<std::endl;
            return 1;
        }
    }
    std::cout<<"Testy ukonczone pomyslnie"<<std::endl;
    return 0;
}