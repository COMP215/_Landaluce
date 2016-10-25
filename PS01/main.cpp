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

    my_graph.InsertEdge("A","B",1);
    my_graph.InsertEdge("B","C",2);
    my_graph.InsertEdge("C","D",6);
    my_graph.InsertEdge("D","E",5);
    my_graph.InsertEdge("E","A",2);
    my_graph.InsertEdge("A","F",3);

    cout << "Graph:" << endl;
    my_graph.Display();

    Graph my_MST;
    my_MST = my_graph.PrimMST();
    cout << endl << "Prim's MST:" << endl;
    my_MST.Display();
    my_MST.ToGraphviz();

    return 0;
}
