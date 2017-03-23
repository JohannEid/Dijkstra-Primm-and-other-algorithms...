#include <iostream>
#include <vector>
#include "Graph.h"
#include "Edges.h"
#include "Summit.h"


int main() {
    Graph a;


    a.solvePrimm();
    a.display_primm();

/*
  a.solveKruskal();
    a.display_kruskal();
    a.readFromFileAdjacency();
    a.solveDijkstra();
    a.display_dijkstra();
*/












    /*
    std::list<Edges> list_of_edge;


    i_edges.insert(Edges(std::make_pair(Summit(1),Summit(2)),5));
    i_edges.insert(Edges(std::make_pair(Summit(3),Summit(4)),1));
    i_edges.insert(Edges(std::make_pair(Summit(6),Summit(5)),3));
    i_edges.insert(Edges(std::make_pair(Summit(1),Summit(5)),4));
    i_edges.insert(Edges(std::make_pair(Summit(4),Summit(3)),8));


    for(auto& elem : i_edges){ list_of_edge.push_back(elem); }
    a.solveKruskal(list_of_edge);
    a.display();
*/



    return 0;
}