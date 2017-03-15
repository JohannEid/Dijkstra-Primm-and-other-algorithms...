//
// Created by johann on 15/03/17.
//

#ifndef TP03_EDGES_H
#define TP03_EDGES_H

#include "Header.h"

class Summit;

class Edges {

    std::pair<std::shared_ptr<Summit>, std::shared_ptr<Summit>> m_summits;
    int m_value;

public:
    Edges(const std::pair<std::shared_ptr<Summit>, std::shared_ptr<Summit>> &summits, int value)
            : m_summits(summits), m_value(value) {}


};


#endif //TP03_EDGES_H
