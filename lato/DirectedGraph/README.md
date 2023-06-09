author: Mateusz Dyszewski
date: 28.03.2023
# Directed Graph + BFS
-----------------------------------
Implementation uses my own implementation of Set and PriorityQueue.
--------------------------------------
## Directed Graph:
### Interface:
#### Constructor:
DirectedGraph(int numVert) constructs graph with number of vertecies passed as argument
#### Methods:
void addEdge(int,int) makes an edge between two vertecies\
void removeEdge(int, int) removes an edge between two vertecies\
bool hasEdge(int, int) checks if edge beetwen two edges exists\
Set<int> inConnections(int) returns set of every vertex going into vertex\
Set<int> outConnections(int) returns set of all edges going out from vertex\
Set<int> allConnections(int) Returns all edges connected to vertex
#### Fields:
const int vertex_count; Field containing size of the graph
    
----------------------------------------
## BFS:
### Interface:
#### Methods: 
int* BFS(DirectedGraph,int)
    arguments: DirectedGraph - graph to perform the operation on; int - starting vertex
    returns: array of ints containing shortest paths to vertexes. Search is started from the vertex passed as an argument
## How to run tests:
`make tester.x` compiles testing program  
`make run` compiles and runs testing program  
`make clean` cleans directory  
