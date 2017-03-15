//
// Created by johann on 15/03/17.
//

#ifndef TP03_SUMMIT_H
#define TP03_SUMMIT_H


class Summit {
private:
    int m_id;
    int m_union;
public:
    Summit(int id) : m_id(id),m_union(id) {}

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


};


#endif //TP03_SUMMIT_H
