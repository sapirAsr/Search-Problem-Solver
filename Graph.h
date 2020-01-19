//
// Created by michal on 17/01/2020.
//

#ifndef MILESTONE2_GRAPH_H
#define MILESTONE2_GRAPH_H



// Program to print Graph traversal from a given
// source vertex. Graph(int s) traverses vertices
// reachable from s.
#include<iostream>
#include <list>

using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph {
    int V; // No. of vertices
    list<int> *adj; // Pointer to an array containing adjacenc lists
public:
    Graph(int V); // Constructor
    // function to add an edge to graph
    void addEdge(int v, int w);
    // prints Graph traversal from a given source s
    void BFS(int s);
};


#endif //MILESTONE2_GRAPH_H
