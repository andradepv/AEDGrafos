#include <iostream>
#include <list>
#include<cstdlib>
#include<limits>
#include <iomanip>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef unsigned int Weight;

class GraphAM {
private:
    uint num_vertices;
    uint num_edges;
    Weight **adj;

public:

    uint get_num_vertices() { return num_vertices; }

    uint get_num_edges() { return num_edges; }

    void remove_edge(Vertex u, Vertex v);

    Weight get_weight_edge(Vertex u, Vertex v){ return adj[u][v]; }

    GraphAM(uint num_vertices) : num_vertices(num_vertices), num_edges(0) {

        adj = new Weight*[num_vertices];
        for (unsigned int i = 0; i < num_vertices; ++i) {
            adj[i] = new Weight[num_vertices];
        }


        for (unsigned int u = 0; u < num_vertices; ++u) {
            for (unsigned int v = 0; v < num_vertices; ++v) {
                adj[u][v] = 0;
            }
        }
    }

    ~GraphAM() {

        for (unsigned int i = 0; i < num_vertices; ++i) {
            delete[] adj[i];
        }
        delete[] adj;
    }

    void addEdge(Vertex u, Vertex v) {
        if (u < num_vertices && v < num_vertices) {
            adj[u][v] = 1;
            adj[v][u] = 1; 
            num_edges++;
        }
    }

    void remove_edge(Vertex u, Vertex v) {
    if (u < num_vertices && v < num_vertices) {
        adj[u][v] = 0;
        adj[v][u] = 0;
        num_edges--;
    }
}

    std::list<Vertex> get_adj(Vertex v) {

        std::list<Vertex> adjacentes;

        if (v < num_vertices) {
            for (Vertex u = 0; u < num_vertices; ++u) {
                if (adj[v][u] != 0) {
                    adjacentes.push_back(u);
                }
            }
        }

        return adjacentes;
    }

    void printAdjMatrix() const {
        for (unsigned int i = 0; i < num_vertices; ++i) {
            for (unsigned int j = 0; j < num_vertices; ++j) {
                std::cout << adj[i][j] << " ";
            }
            std::cout << "\n";
        }
    }


};

int main() {

    uint num_vertices;
    uint num_edges;

    std::cin >> num_vertices;
    std::cin >> num_edges;

    GraphAM graph(num_vertices);

    for (unsigned int i = 0; i < num_edges; ++i) {
        Vertex u, v;
        std::cin >> u >> v;
        graph.addEdge(u, v);
    }

    std::cout << "num_vertices: " << graph.get_num_vertices() << "\n";
    std::cout << "num_edges: " << graph.get_num_edges() << "\n";

    graph.printAdjMatrix();

    return 0;
}
