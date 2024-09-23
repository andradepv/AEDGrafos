#include <iostream>
#include <list>
#include<cstdlib>
#include<limits>
#include <iomanip>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef float Weight;

class VertexWeightPair {
public:
    Vertex vertex; 
    Weight weight;  

    VertexWeightPair(Vertex v, Weight w) : vertex(v), weight(w) {}
};

class WeightedGraphAL {
private:
    unsigned int num_vertices;
    unsigned int num_edges;
    std::list<VertexWeightPair>* adj;

public:
    WeightedGraphAL(unsigned int num_vertices) : num_vertices(num_vertices), num_edges(0) {
        adj = new std::list<VertexWeightPair>[num_vertices];
    }

    ~WeightedGraphAL() {
        delete[] adj;
    }

    uint get_num_vertices() { return num_vertices; }

    uint get_num_edges() { return num_edges; }

    void addEdge(Vertex u, Vertex v, Weight w) {
        adj[u].emplace_back(v, w); 
        adj[v].emplace_back(u, w); 
        num_edges++;
    }

    void remove_edge(Vertex u, Vertex v) {
        adj[u].remove_if([v](const VertexWeightPair& pair) {
            return pair.vertex == v;
        });

        adj[v].remove_if([u](const VertexWeightPair& pair) {
            return pair.vertex == u;
        });

        num_edges--;
    }

    std::list<VertexWeightPair> get_adj(Vertex u) {
        return adj[u];
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

};

int main() {
    unsigned int num_vertices, num_edges;

    std::cin >> num_vertices >> num_edges;

    WeightedGraphAL graph(num_vertices);

    for (unsigned int i = 0; i < num_edges; ++i) {
        Vertex u, v;
        Weight w;
        std::cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    std::cout << "num_vertices: " << graph.get_num_vertices() << "\n";
    std::cout << "num_edges: " << graph.get_num_edges() << "\n";

    graph.printAdjList();

    return 0;
}
