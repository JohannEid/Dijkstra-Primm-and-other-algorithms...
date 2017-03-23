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
    int m_order = 0;
    int m_number_of_edges = 0;
    int m_visited_summits = 0;
    std::vector<Summit> m_summits;
    std::vector<Edges> m_primm_algorithms;
    std::vector<Edges> m_smallest_weight_tree;



    void solveUnions(const Edges &to_unite,std::multiset<Edges>& edges_collection);
    void display_graph(std::vector<Edges>& to_display);
    void create_summit_collection();
    std::vector<std::vector<int >>  readFromFileAdjacency();
    std::multiset<Edges> readFromFile();




public:

    void display();

    void display_dijkstra();

    void display_primm ();

    void display_kruskal();

    void solveKruskal();

    void solvePrimm();

    void solveDijkstra() ;


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

    const std::vector<Summit> &getM_summits() const {
        return m_summits;
    }

    int get_visited_summits() const {
        return m_visited_summits;
    }

    void increment_visited_summits() {
    ++m_visited_summits;    }
};


#endif //TP03_GRAPH_H
