#include "DirectedGraph.hpp"


void DirectedGraph::addEdge(int a,int b){
    if(b > vertex_count||a>vertex_count){return;}
    vertexes[a].insert(b);
}

void DirectedGraph::removeEdge(int a,int b){
    if(b > vertex_count || a>vertex_count){return;}
    vertexes[a].remove(b);
}

bool DirectedGraph::hasEdge(int a,int b){
    return vertexes[a].isMember(b);
}
Set<int> DirectedGraph::inConnections(int i){
    Set<int> connections;
    for (int j = 0;j<vertex_count;j++){
        if(vertexes[j].isMember(i)){
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
