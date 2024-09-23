#include <iostream>
#include <list>


typedef unsigned int Vertex;

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

    void printGraphInfo() const {
        std::cout << "num_vertices: " << num_vertices << "\n";
        std::cout << "num_edges: " << num_edges << "\n";
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

    graph.printGraphInfo();
    graph.printAdjList();

    return 0;
}
