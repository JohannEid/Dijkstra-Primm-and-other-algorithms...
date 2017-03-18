//
// Created by johann on 15/03/17.
//

#include "Graph.h"

Graph::Graph() {
    readFromFile();
}

void Graph::readFromFile() {
    int compteur{0};
    int value{0};
    std::vector<int> temporary_values;
    std::string line;
    std::ifstream myfile("source.txt");
    if (myfile.is_open()) {
        while (myfile >> value) {
            ++compteur;

            if (compteur == 1) { setOrder(value); }
            else if (compteur == 2) { setNumber_of_edges(value); }
            else if (compteur > getNumber_of_edges() * 2 + getOrder() + 3) { break; }
            else if (((compteur - 2) % 3 == 0) && (compteur > 2)) {
                temporary_values.push_back(value);
                m_edges_collection.insert(Edges(std::make_pair(Summit(temporary_values[(compteur - 5)]),
                                                               Summit(temporary_values[(compteur - 4)])),
                                                temporary_values[compteur - 3]));

            } else {
                temporary_values.push_back(value);
            }
        }
        myfile.close();


    } else { std::cout << "Couldn't open file" << std::endl; }
}

void Graph::solveKruskal(std::list<Edges> &list_of_edge) {

    for (auto &elem : list_of_edge) {
        if (elem.getSummits().first.getUnion() != elem.getSummits().second.getUnion())
            addEdges(elem);
        solveUnions(elem, list_of_edge);
    }
}

void Graph::solveUnions(Edges &to_unite, std::list<Edges> &i_edges) {
    int uni_lhs{to_unite.getSummits().first.getUnion()};
    int uni_rhs{to_unite.getSummits().second.getUnion()};

    for (auto &elem : i_edges) {
        if (elem.getSummits().first.getUnion() == uni_rhs) { elem.setUnion(true, uni_lhs); }
        else if (elem.getSummits().second.getUnion() == uni_rhs) {
            elem.setUnion(false, uni_lhs);
        }
    }
}


void Graph::display() {
    std::cout << getOrder() << std::endl;
    std::cout << getNumber_of_edges() << std::endl;
    for (const auto &elem : m_edges_collection) {
        std::cout << elem.getSummits().first.getId() << " ";
        std::cout << elem.getSummits().second.getId() << " ";
        std::cout << elem.getValue() << std::endl;
    }

}

