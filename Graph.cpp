//
// Created by johann on 15/03/17.
//

#include "Graph.h"


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
                // else if (compteur > getNumber_of_edges() * 2 + getOrder() + 3) { break; }
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

void Graph::solveKruskal() {
    int compteur = 0;
    for (auto &elem : m_edges_collection) {
        if (elem.getSummits().first.getUnion() != elem.getSummits().second.getUnion())
            m_smallest_weight_tree.insert(elem);
        solveUnions(elem);

    }
}

void Graph::solveUnions(const Edges &to_unite) {
    int uni_lhs{to_unite.getSummits().first.getUnion()};
    int uni_rhs{to_unite.getSummits().second.getUnion()};

    for (auto &elem : getM_edges_collection()) {
        if (elem.getSummits().first.getUnion() == uni_rhs) { elem.m_summits.first.setUnion(uni_lhs); }
        else if (elem.getSummits().second.getUnion() == uni_rhs) {
            elem.m_summits.second.setUnion(uni_lhs);
        }
    }
}


void Graph::display() {
    std::cout << "INITIAL INPUT IS " << std::endl;
    std::cout << getOrder() << std::endl;
    std::cout << getNumber_of_edges() << std::endl;
    display_graph(m_edges_collection);
    std::cout << "SMALLEST WEIGHT TREE IS " << std::endl;
    display_graph(m_smallest_weight_tree);
    std::cout << "PRIMM ALGORITHM" << std::endl;
    display_graph(m_primm_algorithms);
}

void Graph::solvePrimm() {
    std::vector<int> is_visited_id;
    is_visited_id.push_back(m_primm_algorithms.begin()->m_summits.first.getId());
    for (auto &elem : m_edges_collection) {
        if ((isVisited(is_visited_id, elem.getSummits().first.getId())) &&
            (!isVisited(is_visited_id, elem.getSummits().second.getId()))) {
            m_primm_algorithms.insert(elem);
            is_visited_id.push_back(elem.m_summits.second.getId());
        } else if ((isVisited(is_visited_id, elem.getSummits().second.getId())) &&
                   (!isVisited(is_visited_id, elem.getSummits().first.getId()))) {
            m_primm_algorithms.insert(elem);
            is_visited_id.push_back(elem.m_summits.first.getId());
        }

    }
}

void Graph::display_graph(std::set<Edges> &to_display) {
    for (const auto &elem : to_display) {
        std::cout << elem.getSummits().first.getId() << " ";
        std::cout << elem.getSummits().second.getId() << " ";
        std::cout << elem.getValue() << std::endl;
    }

}

bool Graph::isVisited(const std::vector<int> &check_in, const int &to_check) {
    if (std::find(check_in.begin(), check_in.end(), to_check) != check_in.end()) {
        return true;
    } else {
        return false;
    }
}

void Graph::displayAdjacency(std::vector<std::vector<int>> &to_dispaly) {
    for (int i{0}; i < to_dispaly.size(); ++i) {
        for (int j{0}; j < to_dispaly.size(); ++j) {
            std::cout << to_dispaly[i][j];
        }
        std::cout << std::endl;
    }

}


void Graph::readFromFileAdjacency() {
    int value{0};
    int compteur{0};
    std::ifstream myfile("adjacency.txt");
    std::vector<int> line;
    std::vector<std::vector<int>> adjacency_matrix;

    if (myfile.is_open()) {
        while (myfile >> value) {
            if (compteur == 0) { setOrder(value); }
            else if (compteur % getOrder() != 0) { line.push_back(value); }
            else if (compteur % getOrder() == 0) {
                line.push_back(value);
                adjacency_matrix.push_back(line);
                line.clear();
            }


            ++compteur;

        }
    } else { std::cout << "Couldn't open file" << std::endl; }
    myfile.close();
    for (int i{0}; i < getOrder(); ++i) {
        for (int j{0}; j < getOrder(); ++j) {
            m_adjacency_set.insert(Edges(std::make_pair(Summit(i), Summit(j)), adjacency_matrix[i][j]));
        }
    }
    // displayAdjacency(adjacency_matrix);
}

void Graph::solveDijkstra() {
    int distance = 0;
    int source{1};
    std::vector<int> is_visited_id;
    int id_lhs{0};
    int id_rhs{0};
    bool end{false};

    is_visited_id.push_back(source);

    while (!end) {
        for (auto &elem : m_adjacency_set) {
            id_lhs = elem.getSummits().first.getId();
            id_rhs = elem.getSummits().second.getId();

            if ((id_lhs == source) && (!isVisited
                    (is_visited_id, id_rhs))) {
                is_visited_id.push_back(id_rhs);
                distance += elem.getValue();
                source = id_rhs;
            } else if ((id_rhs == source) && (!isVisited
                    (is_visited_id, id_lhs))) {
                is_visited_id.push_back(id_lhs);
                distance += elem.getValue();
                source = id_lhs;
            } else { end = true; }
        }

    }
    std::cout << distance;
    for (const auto &elem : is_visited_id) {
        std::cout << "Visited: " << elem << ",";
    }
}









