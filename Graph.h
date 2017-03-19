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
    std::set<Edges> m_smallest_weight_tree;
    std::set<Edges> m_primm_algorithms;
    std::set<Edges> m_adjacency_set;

    void solveUnions(const Edges &to_unite);
    void display_graph(std::set<Edges>& to_display);


public:


    void displayAdjacency(std::vector<std::vector<int>>& to_dispaly);

    void display();

    void solveKruskal();

    void solvePrimm();

    void solveDijkstra();

    void readFromFile();

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

    const std::set<Edges> &getM_edges_collection() const {
        return m_edges_collection;
    }

    void readFromFileAdjacency();

    bool isVisited(const std::vector<int>& check_in,const int& to_check);

};


#endif //TP03_GRAPH_H
