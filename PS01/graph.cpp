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
        int i = 0;
        vector<Edge*>::iterator iter;
        for (iter = vertices_.begin(); iter != vertices_.end(); ++iter) {
            cout << (*iter)->name_ << "(" << weights_[i] << ") ";
            i++;
        }
        cout << endl;
    } else {
        cout << "no vertices" << endl;
    }
}

void Edge::ToGraphviz(ofstream& fout) {
    if(!vertices_.empty()) {
        vector<Edge*>::iterator iter;
        int pos = 0;
        for (iter = vertices_.begin(); iter != vertices_.end(); ++iter) {
            fout << " " << name_ << " -> " << (*iter)->name_
                 << "[weight=\"" << weights_[pos] << "\", "
                 << "label=\"" << weights_[pos] << "\"];"
                 << endl;
            pos++;
        }
    }
}

Graph Graph::operator=(const Graph& graph) {
    edges_ = graph.edges_;
    return *this;
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
    //Edge* my_pointer = &new_vertex;
    edges_.push_back(new_vertex);

    return true;
}

bool Graph::InsertEdge(string source,string target,int weight) {
    if(!edges_.empty()) {
        Edge* edge1 = new Edge;
        Edge* edge2 = new Edge;
        edge1 = NULL;
        edge2 = NULL;
        vector<Edge>::iterator iter;
        for (iter = edges_.begin(); iter != edges_.end(); iter++) {
            if((*iter).name_ == source) { // find source in graph
                edge1 = &(*iter);
            }
            if((*iter).name_ == target) { // find vetex2 in graph
                edge2 = &(*iter);
            }
        }
        if(edge1 && edge2) { // both vertices in graph
            if(edge1->SearchVertex(target)) { //edge already exist
                return false;
            }
            edge1->vertices_.push_back(edge2);
            edge1->weights_.push_back(weight);
            edge2->reachable_ = true;
            return true;
        } else if(!edge1) {
            cout << "ERROR: could not add vertex between "
                 << source << " and " << target << ": "
                 << source << " is not an edge" << endl;
        } else if(!edge2) {
            cout << "ERROR: could not add vertex between "
                 << source << " and " << target << ": "
                 << target << " is not an edge" << endl;
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
    return true;
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
        /*cout << endl << "Sorted graph: ";
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
        cout << endl;*/
    } else {
        cout << "Empty graph" << endl;
    }
}
void Graph::ToGraphviz() {
    if(!edges_.empty()) {
        ofstream fout;
        fout.open ("graph.dot");
        fout.close();
        fout.open ("graph.dot",ios::app);
        vector<Edge>::iterator iter;
        vector<string>::iterator iter2;
        vector<Edge*>::iterator iter3;
        vector<string> sorted_graph;
        fout << "digraph g {" << endl;
        for (iter = edges_.begin(); iter != edges_.end(); iter++) {
            (*iter).ToGraphviz(fout);
        }
        fout << "}";
        fout.close();
    } else {
        cout << "Empty graph" << endl;
    }
}
int Graph::GetNumberOfEdges() {
    return edges_.size();
}
Vertex::Vertex(string edge1,string edge2,int weight) {
    edge1_ = edge1;
    edge2_ = edge2;
    weight_ = weight;
}
Graph Graph::PrimMST() {
    Graph MST;
    if(!edges_.empty()) {

        //MST.InsertVertex(edges_[0].name_);
        vector<Edge>::iterator iter1;
        vector<Edge*>::iterator iter2;
        int w = 0;
        int e = 0;
        int i = 0;
        vector<Vertex*> open;
        vector<Vertex*> close;
        int max_weight = 0;
        int min_weight = 1000;
        int min_index = 0;
        for (iter1 = edges_.begin(); iter1 != edges_.end(); iter1++) {
                w = 0;
            for (iter2 = (*iter1).vertices_.begin(); iter2 != (*iter1).vertices_.end(); iter2++) {
                Vertex *new_vertex = new Vertex((*iter1).name_, (*iter2)->name_, edges_[e].weights_[w]);
                open.push_back(new_vertex);
                if(edges_[e].weights_[w] > max_weight) {
                    max_weight = edges_[e].weights_[w];
                }
                else if(edges_[e].weights_[w] < min_weight){
                    min_weight = edges_[e].weights_[w];
                    min_index = i;
                }
                w++;
                i++;
            }
            e++;
        }
        MST.InsertVertex(open[min_index]->edge1_);
        MST.InsertVertex(open[min_index]->edge2_);
        cout << open[min_index]->edge1_ << ":" << open[min_index]->edge2_ << " " << open[min_index]->weight_ << endl;
        close.push_back(open[min_index]);
        open.erase(open.begin()+min_index);

        int index = -1;
        min_weight = max_weight;
        vector<Vertex*>::iterator open_iter;
        vector<Vertex*>::iterator close_iter;
        i = 0;
        while(MST.edges_.size() < edges_.size()) {
                i = 0;
            for (open_iter = open.begin(); open_iter != open.end(); open_iter++) {

                for (close_iter = close.begin(); close_iter != close.end(); close_iter++) {
                    cout << (*open_iter)->edge1_ << ":" << (*open_iter)->edge2_ << "(" << (*open_iter)->weight_ << ") ? " <<
                    (*close_iter)->edge1_ << ":" << (*close_iter)->edge2_  << " " << min_weight << endl;
                    if(((*open_iter)->weight_ < min_weight) && (((*open_iter)->edge1_ == (*close_iter)->edge1_)
                                                             || ((*open_iter)->edge1_ == (*close_iter)->edge2_)
                                                             || ((*open_iter)->edge2_ == (*close_iter)->edge1_)
                                                             || ((*open_iter)->edge2_ == (*close_iter)->edge2_))) {
                        cout << "yes" << endl;
                        min_weight = (*open_iter)->weight_;
                        index = i;
                    }
                }
                i++;
            }
            if(index != -1) {
                cout << open[index]->edge1_ << endl;
                MST.InsertVertex(open[index]->edge1_);
                MST.InsertVertex(open[index]->edge2_);
                close.push_back(open[index]);
                open.erase(open.begin() + index);
                min_weight = max_weight;
                index = -1;
            }
            i++;

        }
        for (close_iter = close.begin(); close_iter != close.end(); close_iter++) {
            MST.InsertEdge((*close_iter)->edge1_,(*close_iter)->edge2_,(*close_iter)->weight_);
        }
        MST.Display();
        MST.ToGraphviz();
    } else {
        cout << "Empty graph" << endl;
    }
    return MST;
}

Graph Graph::KruskalMST() {
    Graph KMST;

    return KMST;
}
