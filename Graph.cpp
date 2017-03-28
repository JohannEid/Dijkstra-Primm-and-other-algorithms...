//
// Created by johann on 15/03/17.
//

#include "Graph.h"


std::multiset<Edges> Graph::readFromFile() {
    int compteur{0};
    int value{0};
    std::vector<int> temporary_values;
    std::multiset<Edges> edges_collection;
    std::ifstream myfile("source.txt");

    if (myfile.is_open()) {
        while (myfile >> value) {
            ++compteur;

            if (compteur == 1) {
                setOrder(value);
                create_summit_collection();
            } else if (compteur == 2) { setNumber_of_edges(value); }
            else if (((compteur - 2) % 3 == 0) && (compteur > 2)) {
                temporary_values.push_back(value);
                edges_collection.insert(Edges(std::make_pair(&m_summits[temporary_values[compteur - 5]],
                                                             &m_summits[temporary_values[compteur - 4]]),
                                              temporary_values[compteur - 3]));

            } else {
                temporary_values.push_back(value);
            }
        }
        myfile.close();


    } else { std::cout << "Couldn't open file" << std::endl; }

    return edges_collection;
}

void Graph::solveKruskal() {
    std::multiset<Edges> edges_collection = readFromFile();

    for (auto &elem : edges_collection) {
        if (elem.getSummits().first->getUnion() != elem.getSummits().second->getUnion())
            m_smallest_weight_tree.push_back(elem);
        solveUnions(elem, edges_collection);

    }
}

void Graph::solveUnions(const Edges &to_unite, std::multiset<Edges> &edges_collection) {
    int uni_lhs{to_unite.getSummits().first->getUnion()};
    int uni_rhs{to_unite.getSummits().second->getUnion()};

    for (auto &elem : edges_collection) {
        if (elem.getSummits().first->getUnion() == uni_rhs) { elem.m_summits.first->setUnion(uni_lhs); }
        else if (elem.getSummits().second->getUnion() == uni_rhs) {
            elem.m_summits.second->setUnion(uni_lhs);
        }
    }
}


void Graph::solvePrimm() {
    std::multiset<Edges> edges_collection = readFromFile();

    edges_collection.begin()->getSummits().first->setVisited(true);
    while (get_visited_summits() < getOrder() - 1) {
        for (auto &elem : edges_collection) {
            if ((elem.getSummits().first->isVisited()) &&
                (!elem.getSummits().second->isVisited())) {
                m_primm_algorithms.push_back(elem);
                elem.getSummits().second->setVisited(true);
                increment_visited_summits();
            } else if ((elem.getSummits().second->isVisited()) &&
                       (!elem.getSummits().first->isVisited())) {
                m_primm_algorithms.push_back(elem);
                elem.getSummits().first->setVisited(true);
                increment_visited_summits();

            }
        }
    }

}

void Graph::display_graph(std::vector<Edges> &to_display) {
    for (const auto &elem : to_display) {
        std::cout << elem.getSummits().first->getId() << " ";
        std::cout << elem.getSummits().second->getId() << " ";
        std::cout << elem.getValue() << std::endl;
    }

}

std::vector<std::vector<int >> Graph::readFromFileAdjacency() {
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

    return adjacency_matrix;
}

void Graph::solveDijkstra() {

    std::vector<std::vector<int>> adjacency_matrix = readFromFileAdjacency();
    std::priority_queue<Summit *, std::vector<Summit *>, std::greater<Summit *>> priority_queue;
    int weight{0};
    int source_id{0};
    int distance{0};
    create_summit_collection();


    for (int i{0}; i < getOrder(); ++i) {
        weight = (i == 0) ? 0 : -1;
        m_summits[i].setWeight(weight);
        priority_queue.push(&m_summits[i]);
    }
    while (!priority_queue.empty()) {
        source_id = priority_queue.top()->getId();

        for (int i{0}; i < getOrder(); ++i) {
            distance = adjacency_matrix[source_id][i];
            weight = distance + m_summits[source_id].getWeight();
            if ((distance > 0) && (!m_summits[i].isVisited()) &&
                ((weight < m_summits[i].getWeight()) ||
                 (m_summits[i].getWeight() == -1))) {
                m_summits[i].setWeight(weight);
                m_summits[i].setM_previous(source_id);
            }
        }
        m_summits[source_id].setVisited(true);
        priority_queue.pop();
    }
}

void Graph::display_dijkstra() {
    for (const auto &elem: getM_summits()) {
        std::cout << "Summit is : " << elem.getId() << "its shortest path is " << elem.getWeight() << std::endl;
    }

}

void Graph::create_summit_collection() {
    m_summits.clear();
    for (int i{0}; i < getOrder(); ++i) {
        m_summits.push_back(Summit(i));
    }

}

void Graph::display_primm() {
    std::cout << "PRIMM ALGORITHM" << std::endl;
    display_graph(m_primm_algorithms);
}

void Graph::display_kruskal() {
    std::cout << "KRUSKAL ALGORITHM" << std::endl;
    display_graph(m_smallest_weight_tree);
}

void Graph::save_to_file(const std::string &file_name) {
    std::ofstream my_file;
    my_file.open(file_name);
    try {
        if (file_name == "primm.txt") {
            save_graph(m_primm_algorithms, file_name);
        } else if (file_name == "kruskal.txt") {
            save_graph(m_smallest_weight_tree, file_name);
        } else if (file_name == "dijkstra.txt") {
            for (const auto &elem: getM_summits()) {
                my_file << "Summit is : " << elem.getId()
                        << "its shortest path is " << elem.getWeight() << std::endl;
            }
        } else {
            throw std::domain_error("wrong input file_name ");
        }
    }
    catch (std::exception const &e) {
        std::cerr << "Erreur" << e.what() << std::endl;
    }
}


void menu_choice(Graph &graph) {
    std::string ichoice{" "};
    int choice{0};

    while (true) {
        std::cout << "Please enter" << std::endl << "1.Kruskal" << std::endl << "2.Primm" << std::endl
                  << "3.Dijkstra" << std::endl << "4.Quit" << std::endl;
        try {

            std::cin >> ichoice;
            choice = std::stoi(ichoice);
            if (choice == 1) {
                graph.solveKruskal();
                graph.display_kruskal();
            } else if (choice == 2) {
                graph.solvePrimm();
                graph.display_primm();

            } else if (choice == 3) {
                graph.solveDijkstra();
                graph.display_dijkstra();
            } else if (choice == 4) {
                break;
            } else {
                throw std::domain_error("Invalid choice ");

            }
        }
        catch (std::exception const &e) {
            std::cerr << "Erreur" << e.what() << std::endl;
        }

    }
}

void Graph::save_graph(std::vector<Edges> &to_display, const std::string &file_name) {
    std::ofstream my_file;
    my_file.open(file_name);

    for (const auto &elem : to_display) {
        my_file << elem.getSummits().first->getId() << " ";
        my_file << elem.getSummits().second->getId() << " ";
        my_file << elem.getValue() << std::endl;
    }
}
