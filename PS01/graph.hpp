//  graph.hpp

#ifndef linkedlist_hpp
#define graph_hpp
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
class Vertex {
    public:
    std::string edge1_;
    std::string edge2_;
    int weight_;
    Vertex();
    Vertex(std::string,std::string,int);
};
class Edge {
public:
    std::string name_;
    std::vector<Edge*> vertices_; // List of edges with vertex to this object
    std::vector<int> weights_;
    bool reachable_;              // True means somethings reaches it
    Edge();
    Edge(std::string);
    bool SearchVertex(std::string);
    void Display();
    void ToGraphviz(std::ofstream&);
};

class Graph {
private:
    std::vector<Edge> edges_;
public:
    Graph operator=(const Graph&);
    bool InsertVertex(std::string);
    bool InsertEdge(std::string,std::string,int weight = 0);
    bool IsBipartite();
    void Display();
    void ToGraphviz();
    Graph PrimMST();
    int GetNumberOfEdges();
    Graph KruskalMST();
};

#endif /* graph_hpp */
