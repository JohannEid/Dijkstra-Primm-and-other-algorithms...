//
// Created by johann on 15/03/17.
//

#ifndef TP03_GRAPH_H
#define TP03_GRAPH_H

#include "Header.h"

class Summit;

class Edges;


class Graph {

private:

    std::shared_ptr<Summit> m_start;
    std::vector<std::shared_ptr<Edges>> m_edges;

public:


    void setEdges(const std::vector<std::unique_ptr<Edges>> &m_edges);

    const std::shared_ptr<Summit> &getStart() const {
        return m_start;
    }

    const std::vector<std::shared_ptr<Edges>> &getEdges() const {
        return m_edges;
    }

};


#endif //TP03_GRAPH_H
