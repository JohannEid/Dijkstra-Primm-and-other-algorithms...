#include <iostream>
#include <vector>
#include "Graph.h"
#include "Edges.h"
#include "Summit.h"


int main() {

Graph a;
    menu_choice(a);
    a.save_to_file("primm.txt");
    a.save_to_file("kruskal.txt");
    a.save_to_file("dijkstra.txt");



    return 0;
}