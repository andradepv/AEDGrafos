#include <iostream>
#include <list>
#include<cstdlib>
#include<limits>
#include <iomanip>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef float Weight;

class DigraphAL {
private:
    unsigned int num_vertices;
    unsigned int num_edges;
    std::list<Vertex>* adj;

public:
    DigraphAL(unsigned int num_vertices)
        : num_vertices(num_vertices), num_edges(0) {
        adj = new std::list<Vertex>[num_vertices];
    }

    ~DigraphAL() {
        delete[] adj;
    }

    uint get_num_vertices() { return num_vertices; }

    uint get_num_edges() { return num_edges; }

    std::list<Vertex> get_adj(Vertex v) { return adj[v]; };

    void DigraphAL::remove_edge(Vertex u, Vertex v) {
    adj[u].remove(v);
    num_edges--;
}

    void addEdge(Vertex u, Vertex v) {
        if (arestaExistente(u, v)) {
            adj[u].push_back(v); 
            num_edges++;
        }
    }

    bool arestaExistente(Vertex u, Vertex v) {
        if (u != v) {
            for (const Vertex& existing_vertex : adj[u]) {
                if (existing_vertex == v) {
                    return false; 
                }
            }
            return true;
        }
        return false;
    }

    void printAdjList() const {
        for (unsigned int u = 0; u < num_vertices; ++u) {
            std::cout << u << ": ";
            for (const auto& v : adj[u]) {
                std::cout << v << ", ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    unsigned int num_vertices, num_edges;

    std::cin >> num_vertices >> num_edges;

    DigraphAL graph(num_vertices);

    for (unsigned int i = 0; i < num_edges; ++i) {
        Vertex u, v;
        std::cin >> u >> v;
        graph.addEdge(u, v);
    }

    std::cout << "num_vertices: " << graph.get_num_vertices() << "\n";
    std::cout << "num_edges: " << graph.get_num_edges() << "\n";
    graph.printAdjList();

    return 0;
}
