// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#ifndef GRAPH_H_
#define GRAPH_H_

#include <list>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };
    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
        bool color;
        bool inStack;
        int num;
        int low;
        int parent;
        int cost;
    };
    bool hasDir;        // false: undirected; true: directed
public:
    vector<Node> nodes; // The list of nodes being represented
    int n; // Graph size (vertices are numbered from 1 to n)
    // Constructor: nr nodes and direction (default: undirected)
    explicit Graph(int nodes, bool dir = false);
    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1);
    // Depth-First Search: example implementation
    void dfs(int v);
    void coloreddfs(int v, bool color);
    void dfs_scc2(int v, stack<int> &st, list<list<int>> &sccs, int &currCount);
    int dfs_count_scc(int v, int &order, stack<int> &s);
    void dfs_articulation_points(int v, int &order, list<int> &l);
    // ----- Functions to implement in this class -----
    bool bipartite();
    int countSCCs();
    list<list<int>> listSCCs();
    list<int> articulationPoints();
};

#endif
