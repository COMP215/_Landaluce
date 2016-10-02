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

    my_graph.InsertEdge("A","E");
    my_graph.InsertEdge("B","F");
    my_graph.InsertEdge("C","G");
    my_graph.InsertEdge("D","H");
    my_graph.InsertEdge("e","e");

    my_graph.Display();

    cout<< "Is Bipartite: " << std::boolalpha << my_graph.IsBipartite() << endl;

    return 0;
}
