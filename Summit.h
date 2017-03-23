//
// Created by johann on 15/03/17.
//

#ifndef TP03_SUMMIT_H
#define TP03_SUMMIT_H


class Summit {
private:
    int m_id;
    int m_previous;
    int weight;
    mutable int m_union;
    mutable bool visited = false;
public:

    Summit(int id) : m_id(id), m_union(id) {}

    Summit(int m_id, int weight, bool visited) : m_id(m_id), weight(weight), visited(visited) {}

    bool operator > (const Summit* rhs)const { return getWeight() > rhs->getWeight(); }

    bool operator < (const Summit* rhs)const { return getWeight() < rhs->getWeight(); }

    void setM_previous(int m_previous) {
        Summit::m_previous = m_previous;
    }

    void setWeight(int weight) {
        Summit::weight = weight;
    }

    int getId() const {
        return m_id;
    }

    void setId(int m_id) {
        Summit::m_id = m_id;
    }

    int getUnion() const {
        return m_union;
    }

    void setUnion(int m_union) {
        Summit::m_union = m_union;
    }

    bool isVisited() const {
        return visited;
    }

    void setVisited(bool visited) {
        Summit::visited = visited;
    }

    int getM_id() const {
        return m_id;
    }

    int getM_previous() const {
        return m_previous;
    }

    int getWeight() const {
        return weight;
    }

    int getM_union() const {
        return m_union;
    }



};


#endif //TP03_SUMMIT_H
