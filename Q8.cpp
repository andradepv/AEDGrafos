#include <iostream>
#include <iomanip>
#include <limits>

typedef unsigned int uint;
typedef unsigned int Vertex;
typedef float Weight;

class WeightedGraphAM {
private:
    unsigned int num_vertices;
    unsigned int num_edges;
    Weight** adj;

public:
    WeightedGraphAM(unsigned int num_vertices)
        : num_vertices(num_vertices), num_edges(0) {
        
        adj = new Weight*[num_vertices];
        for (unsigned int i = 0; i < num_vertices; ++i) {
            adj[i] = new Weight[num_vertices];
        }

        Weight inf = std::numeric_limits<Weight>::infinity();
        for (unsigned int i = 0; i < num_vertices; ++i) {
            for (unsigned int j = 0; j < num_vertices; ++j) {
                    adj[i][j] = inf;
            }
        }
    }

    ~WeightedGraphAM() {
        for (unsigned int i = 0; i < num_vertices; ++i) {
            delete[] adj[i];
        }
        delete[] adj;
    }

    void addEdge(Vertex u, Vertex v, Weight w) {
        Weight inf = std::numeric_limits<Weight>::infinity();
        if(adj[u][v]==inf){
        num_edges++;
        }
        adj[u][v] = w;

    }

    void printGraphInfo() const {
        std::cout << "num_vertices: " << num_vertices << "\n";
        std::cout << "num_edges: " << num_edges << "\n";
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

    WeightedGraphAM graph(num_vertices);

    for (unsigned int i = 0; i < num_edges; ++i) {
        Vertex u, v;
        Weight w;
        std::cin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    graph.printGraphInfo();
    graph.printAdjMatrix();

    return 0;
}
