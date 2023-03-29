#include <cstring>
#include "BFS.hpp"

int* BFS(DirectedGraph G,int s){
    int* visited_nodes = new int[G.vertex_count];
    std::memset( visited_nodes ,0,G.vertex_count);
    PriorityQueue<int> kolejka;
    kolejka.insert(s,0);
    int ile_sasiadow = 1,level = 0;
    int prio = G.vertex_count;
    while(kolejka.size()>0){
        int extracted = kolejka.extractmax().obj;
        for(int connection : G.outConnections(extracted)){
            if(visited_nodes[connection]==0 ){
                kolejka.insert(connection,prio);
                visited_nodes[connection] = level+1;
                prio--;
            }
        }
        ile_sasiadow--;
        if(!ile_sasiadow){
            level++;
            ile_sasiadow = kolejka.size();
        }
    }
    return visited_nodes;
}
