#include <iostream>
#include <list>
#include <iomanip>

typedef unsigned int Vertex;
typedef float Weight;

class VertexWeightPair {
public:
    Vertex vertex; 
    Weight weight;  

    VertexWeightPair(Vertex v, Weight w) : vertex(v), weight(w) {}
};

class WeightedDigraphAL {
private:
    unsigned int num_vertices;
    unsigned int num_edges;
    std::list<VertexWeightPair>* adj;

public:
    WeightedDigraphAL(unsigned int num_vertices) : num_vertices(num_vertices), num_edges(0) {
        adj = new std::list<VertexWeightPair>[num_vertices];
    }

    ~WeightedDigraphAL() {
        delete[] adj;
    }

    void addEdge(Vertex u, Vertex v, Weight w) {
        adj[u].emplace_back(v, w); 
        num_edges++;
    }

    void printAdjList() const {
        for (unsigned int u = 0; u < num_vertices; ++u) {
            std::cout << u << ": ";
            for (const auto& pair : adj[u]) {
                std::cout << "(" << pair.vertex << ", " << pair.weight << "), ";
            }
            std::cout << "\n";
        }
    }

    void printGraphInfo() const {
        std::cout << "num_vertices: " << num_vertices << "\n";
        std::cout << "num_edges: " << num_edges << "\n";
    }
};

int main() {
    unsigned int num_vertices, num_edges;

    std::cin >> num_vertices >> num_edges;

    WeightedDigraphAL graph(num_vertices);

    for (unsigned int i = 0; i < num_edges; ++i) {
        Vertex u, v;
        Weight w;
        std::cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.printGraphInfo();

    graph.printAdjList();

    return 0;
}
