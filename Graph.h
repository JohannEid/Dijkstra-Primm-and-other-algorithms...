//
// Created by johann on 15/03/17.
//

#ifndef TP03_GRAPH_H
#define TP03_GRAPH_H

#include "Header.h"
#include "Summit.h"
#include "Edges.h"

class Summit;

class Edges;


class Graph {

private:
    std::vector<Edges> m_edges;

public:


    void display();
    void solveKruskal( std::list<Edges>& list_of_edge);
    void solveUnions (Edges to_unite,std::list<Edges>& i_edges);
    void addEdges(const Edges& edge_to_add){m_edges.push_back(edge_to_add);}


};


#endif //TP03_GRAPH_H
