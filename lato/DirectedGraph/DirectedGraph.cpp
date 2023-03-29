#include "DirectedGraph.hpp"


void DirectedGraph::addEdge(int a,int b){
    vertexes[a].push_back(b);
}

void DirectedGraph::removeEdge(int a,int b){
    vertexes[a].remove(b);
}

bool DirectedGraph::hasEdge(int a,int b){
    return vertexes[a].find(b) != vertexes[a].end();
}
Set<int> DirectedGraph::inConnections(int i){
    Set<int> connections;
    for (int j = 0;j<vertex_count;j++){
        if(vertexes[j].find(i) != vertexes[j].end()){
            connections.insert(j);
        }
    }
    return connections;
}
Set<int> DirectedGraph::outConnections(int i){
    Set<int> connections;
    for(auto a : vertexes[i]){
        connections.insert(a);
    }
    return connections;
}

Set<int> DirectedGraph::allConnections(int i){
    return outConnections(i).unions(inConnections(i));
}
