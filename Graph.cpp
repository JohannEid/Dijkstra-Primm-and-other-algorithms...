//
// Created by johann on 15/03/17.
//

#include "Graph.h"


void Graph :: solveKruskal( std::list<Edges>& list_of_edge) {

    for ( std::list<Edges>::iterator elem = list_of_edge.begin();elem!=list_of_edge.end();
          ++elem) {
        if (elem->getSummits().first.getUnion() != elem->getSummits().second.getUnion())
            addEdges(*elem);
            solveUnions(*elem,list_of_edge);
       // list_of_edge.erase(elem);
    }
}

void Graph::solveUnions(Edges to_unite, std::list<Edges>& i_edges) {
    int uni_lhs{to_unite.getSummits().first.getUnion()};
    int uni_rhs{to_unite.getSummits().second.getUnion()};

    for (auto& elem : i_edges) {
        if (elem.getSummits().first.getUnion() == uni_rhs) { elem.setUnion(true,uni_lhs); }
        else if (elem.getSummits().second.getUnion() == uni_rhs) {
            elem.setUnion(false,uni_lhs);        }
    }
}


void Graph::display() {
    for(const auto& elem : m_edges){
        std::cout <<elem.getValue()<<std::endl;
    }

}
