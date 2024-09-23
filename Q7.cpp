#include <iostream>
#include <list>
#include<cstdlib>
#include<limits>
#include <iomanip>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef unsigned int Weight;

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

    uint get_num_vertices() { return num_vertices; };

    uint get_num_edges() { return num_edges; };

    WeightedDigraphAL(unsigned int num_vertices) : num_vertices(num_vertices), num_edges(0) {
        adj = new std::list<VertexWeightPair>[num_vertices];
    }

    ~WeightedDigraphAL() {
        delete[] adj;
    }

    std::list<VertexWeightPair> get_adj(Vertex u) {
        if (u < num_vertices) {
            return adj[u];
        }
        return std::list<VertexWeightPair>();
    }

    void remove_edge(Vertex u, Vertex v) {
        for (auto it = adj[u].begin(); it != adj[u].end(); ++it) {
            if (it->vertex == v) {  
                adj[u].erase(it);   
                num_edges--;        
                break;
            }
        }
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

    std::cout << "num_vertices: " << graph.get_num_vertices() << "\n";
    std::cout << "num_edges: " << graph.get_num_edges() << "\n";
    graph.printAdjList();

    return 0;
}
