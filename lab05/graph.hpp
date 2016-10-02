//  graph.hpp

#ifndef linkedlist_hpp
#define graph_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

class Edge {
public:
    std::string name_;
    std::vector<Edge*> vertices_; // List of edges with vertex to this object
    bool reachable_;              // True means somethings reaches it
    Edge();
    Edge(std::string);
    bool SearchVertex(std::string);
    void Display();
};


class Graph {
private:
    std::vector<Edge> edges_;
public:
    bool InsertVertex(std::string);
    bool InsertEdge(std::string,std::string);
    bool IsBipartite();
    void Display();
};


#endif /* graph_hpp */
