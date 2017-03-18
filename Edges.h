//
// Created by johann on 15/03/17.
//

#ifndef TP03_EDGES_H
#define TP03_EDGES_H

#include "Header.h"
#include "Summit.h"


class Edges {

    int m_value;

public:
    mutable std::pair<Summit,Summit> m_summits;

    Edges(const std::pair<Summit,Summit> &summits, int value)
            : m_value(value),m_summits(summits)
    {}



    bool operator < ( const Edges &rhs) const {
        return m_value < rhs.m_value;
    }

       const std::pair<Summit, Summit> &getSummits() const   {
        return m_summits;
    }

    int getValue() const {
        return m_value;
    }
   void setUnion(bool isFirst, int uni_to_set){
     if(isFirst) {m_summits.first.setUnion(uni_to_set);}
     else {m_summits.second.setUnion(uni_to_set);}
   }
};


#endif //TP03_EDGES_H
