#include <iostream>
#include "graph.hpp"

using namespace std;

int main()
{
    Graph my_graph;
    my_graph.InsertVertex("A");
    my_graph.InsertVertex("B");
    my_graph.InsertVertex("C");
    my_graph.InsertVertex("D");
    my_graph.InsertVertex("E");
    my_graph.InsertVertex("F");
    my_graph.InsertVertex("G");
    my_graph.InsertVertex("H");
    my_graph.InsertEdge("B","A",9);
    my_graph.InsertEdge("A","B",2);
    my_graph.InsertEdge("A","C",1);
    my_graph.InsertEdge("C","D",3);
    my_graph.InsertEdge("D","B",4);
    my_graph.InsertEdge("E","E",4);

    //my_graph.Display();

    //cout<< "Is Bipartite: " << std::boolalpha << my_graph.IsBipartite() << endl;

    my_graph.ToGraphviz();

    return 0;
}
