//
// Created by johann on 15/03/17.
//

#ifndef TP03_GRAPH_H
#define TP03_GRAPH_H

#include "Header.h"
#include "Summit.h"
#include "Edges.h"

class Graph {

private:
    int m_order;
    int m_number_of_edges;
    std::vector<Edges> m_edges;
    std::set<Edges> m_edges_collection;

    void readFromFile();
    void solveUnions(Edges &to_unite, std::list<Edges> &i_edges);


public:

    Graph();

    void display();

    void solveKruskal(std::list<Edges> &list_of_edge);

    void addEdges(const Edges &edge_to_add) { m_edges.push_back(edge_to_add); }

    int getOrder() const {
        return m_order;
    }

    void setOrder(int order) {
        Graph::m_order = order;
    }

    int getNumber_of_edges() const {
        return m_number_of_edges;
    }

    void setNumber_of_edges(int number_of_edges) {
        Graph::m_number_of_edges = number_of_edges;
    }


};


#endif //TP03_GRAPH_H
