//  graph.cpp

#include "graph.hpp"
#include <string>
#include <algorithm>
#include <set>

using namespace std;

Edge::Edge() {}

Edge::Edge(string name) {
    name_ = name;
    reachable_ = false;
}

bool Edge::SearchVertex(string vertex) {
    vector<Edge*>::const_iterator iter;
    if(!vertices_.empty()) {
        for (iter = vertices_.begin(); iter != vertices_.end(); ++iter)
            if((*iter)->name_ == vertex) {
                return true;
            }
    }
    return false;
}

void Edge::Display() {
    if(!reachable_) {
        cout << "*" << name_ << ": ";
    } else {
        cout << " " << name_ << ": ";
    }
    if(!vertices_.empty()) {
        vector<Edge*>::iterator iter;
        for (iter = vertices_.begin(); iter != vertices_.end(); ++iter) {
            cout << (*iter)->name_ << ", ";
        }
        cout << endl;
    } else {
        cout << "no vertices" << endl;
    }
}

bool Graph::InsertVertex(string vertex) {
    if(!edges_.empty()) {
        vector<Edge>::iterator iter;
        for (iter = edges_.begin(); iter != edges_.end(); iter++) {
            if((*iter).name_ == vertex) {
                return false; // already in the graph
            }
        }
    }
    Edge new_vertex(vertex);
    Edge* my_pointer = &new_vertex;
    edges_.push_back(new_vertex);

    return true;
}

bool Graph::InsertEdge(string vertex1,string vertex2) {
    if(!edges_.empty()) {
        Edge* edge1 = new Edge;
        Edge* edge2 = new Edge;
        edge1 = NULL;
        edge2 = NULL;
        vector<Edge>::iterator iter;
        for (iter = edges_.begin(); iter != edges_.end(); iter++) {
            if((*iter).name_ == vertex1) { // find vertex1 in graph
                edge1 = &(*iter);
            }
            if((*iter).name_ == vertex2) { // find vetex2 in graph
                edge2 = &(*iter);
            }
        }
        if(edge1 && edge2) { // both vertices in graph
            if(edge1->SearchVertex(vertex2)) { //edge already exist
                return false;
            }
            edge1->vertices_.push_back(edge2);
            edge2->reachable_ = true;
            return true;
        } else if(!edge1) {
            cout << "ERROR: could not add vertex between "
                 << vertex1 << " and " << vertex2 << ": "
                 << vertex1 << " is not an edge" << endl;
        } else if(!edge2) {
            cout << "ERROR: could not add vertex between "
                 << vertex1 << " and " << vertex2 << ": "
                 << vertex2 << " is not an edge" << endl;
        }
    }
    return false;
}

bool Graph::IsBipartite() {
    set<string> group1, group2;
    vector<Edge>::iterator iter;
    vector<Edge*>::iterator iter2;
    short second_group = 0;
    if(!edges_.empty()) {
        for (iter = edges_.begin(); iter != edges_.end(); iter++) {
            second_group = 0;
            if(!(group1.find((*iter).name_) != group1.end()) && !(group2.find((*iter).name_) != group2.end())) {
                group1.insert((*iter).name_);
                second_group = 2;
            } else if(!(group2.find((*iter).name_) != group2.end())) {
                group2.insert((*iter).name_);
                second_group = 1;
            }
            for (iter2 = (*iter).vertices_.begin();iter2 != (*iter).vertices_.end();iter2++) {
                if(second_group == 2) {
                    if(group1.find((*iter2)->name_) != group1.end()) {
                        return false;
                    } else {
                        group2.insert((*iter2)->name_);
                    }
                } else if(second_group == 1) {
                    if(group2.find((*iter2)->name_) != group2.end()) {
                        return false;
                    } else {
                        group1.insert((*iter2)->name_);
                    }
                } else {
                    return false;
                }
            }
        }
        return true;
    }
}
void Graph::Display() {


    if(!edges_.empty()) {
        vector<Edge>::iterator iter;
        vector<string>::iterator iter2;
        vector<Edge*>::iterator iter3;
        vector<string> sorted_graph;
        cout << "Unsorted graph: * = unreachable" << endl;
        for (iter = edges_.begin(); iter != edges_.end(); iter++) {
            (*iter).Display();
        }
        cout << endl << "Sorted graph: ";
        for (iter = edges_.begin(); iter != edges_.end(); iter++) {
            if(!(*iter).reachable_)
            {
                if(!(std::find(sorted_graph.begin(), sorted_graph.end(), (*iter).name_) != sorted_graph.end())) {
                    sorted_graph.push_back((*iter).name_);
                }
                for (iter3 = (*iter).vertices_.begin();iter3 != (*iter).vertices_.end();iter3++) {
                    if(!(std::find(sorted_graph.begin(), sorted_graph.end(), (*iter3)->name_) != sorted_graph.end())) {
                        sorted_graph.push_back((*iter3)->name_);
                    }
                }
            }
        }
        for (iter2 = sorted_graph.begin(); iter2 != sorted_graph.end(); iter2++) {
            cout << *iter2 << ", ";
        }
        cout << endl;
    } else {
        cout << "Empty graph" << endl;
    }
}
