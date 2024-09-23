#include <iostream>
#include <list>
#include<cstdlib>
#include<limits>
#include <iomanip>

typedef unsigned int uint;
typedef unsigned int Vertex;

class GraphAL {
private:
    uint num_vertices;
    uint num_edges;
    std::list<Vertex> *adj;

public:
    GraphAL(uint num_vertices);
    ~GraphAL();
    void add_edge(Vertex u, Vertex v);
    void remove_edge(Vertex u, Vertex v);
    std::list<Vertex> get_adj(Vertex v) { return adj[v]; };
    uint get_num_vertices() { return num_vertices; };
    uint get_num_edges() { return num_edges; };
};

GraphAL::GraphAL(uint num_vertices) : num_vertices(num_vertices) {
    adj = new std::list<Vertex>[num_vertices + 1];
    num_edges = 0;
}

GraphAL::~GraphAL() {
    for (uint i = 0; i < num_vertices; ++i) {
        adj[i].clear();
    }
    delete[] adj;
    adj = nullptr;
    num_vertices = num_edges = 0;
}

void GraphAL::add_edge(Vertex u, Vertex v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    num_edges++;
}

void GraphAL::remove_edge(Vertex u, Vertex v) {
    adj[u].remove(v);
    adj[v].remove(u);
    num_edges--;
}

void print_list(std::list<Vertex> adj) {
    for (auto v: adj) {
        std::cout << v << ", ";
    }
}

void display_graph(GraphAL& g) {
    for (Vertex v = 0; v < g.get_num_vertices(); ++v) {
        std::cout << v << ": ";
        std::list<Vertex> adj = g.get_adj(v);
        print_list(adj);
        std::cout << "\n";
    }

};

int main() {
    uint num_vertices;
    uint num_edges;
    std::cin >> num_vertices;
    std::cin >> num_edges;
    int a, b;

    GraphAL g(num_vertices);
    for (uint i = 0; i < num_edges; i++) {
        std::cin >> a;
        std::cin >> b;
        g.add_edge(a, b);
    }

    std::cout << "num_vertices: " << g.get_num_vertices() << "\n";
    std::cout << "num_edges: " << g.get_num_edges() << "\n";
    display_graph(g);
    return 0;
}