#include <iostream>
#include <iomanip>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef unsigned int Weight;

class GraphAM {
private:
    unsigned int num_vertices;
    unsigned int num_edges;
    Weight **adj;

public:

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
        if (arestaExistente(u, v)) {
            adj[u][v] = 1;
            num_edges++;
        }
    }
    
        bool arestaExistente(Vertex u, Vertex v) {
        if (u != v && adj[u][v] == 0) {
            return true;
        }
        return false;
    }

    void printAdjMatrix() const {
        for (unsigned int i = 0; i < num_vertices; ++i) {
            for (unsigned int j = 0; j < num_vertices; ++j) {
                std::cout << adj[i][j] << " ";
            }
            std::cout << "\n";
        }
    }


    unsigned int getNumEdges() const {
        return num_edges;
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

    std::cout << "num_vertices: " << num_vertices << "\n";
    std::cout << "num_edges: " << graph.getNumEdges() << "\n";

    graph.printAdjMatrix();

    return 0;
}
