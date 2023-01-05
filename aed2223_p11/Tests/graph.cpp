// AED 2022/2023 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [last update: 04/12/2022]

#include "graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num + 1) {}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src < 1 || src > n || dest < 1 || dest > n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

void Graph::coloreddfs(int v, bool color) {
    // show node order
    cout << v << " ";
    nodes[v].visited = true;
    nodes[v].color = color;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            coloreddfs(w, !nodes[v].color);
    }
}

int Graph::dfs_count_scc(int v, int &order, stack<int> &s) {
    nodes[v].visited = true;
    nodes[v].num = nodes[v].low = order++;
    s.push(v);
    nodes[v].inStack = true;

    int count = 0;
    for (Edge e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            count += dfs_count_scc(w, order, s);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        else if (nodes[w].inStack) {
            nodes[v].low = min(nodes[v].low, nodes[w].num);
        }
    }

    if (nodes[v].low == nodes[v].num) {
        int w;
        do {
            w = s.top();
            s.pop();
            nodes[w].inStack = false;
        } while (w != v);
        count++;
    }

    return count;
}

void Graph::dfs_scc2(int v, stack<int> &st, list<list<int>> &sccs, int &currCount) {
    nodes[v].visited = true;
    nodes[v].num = currCount++;
    int num = nodes[v].num;
    st.push(v);
    nodes[v].inStack = true;
    nodes[v].low = num;
    for (const Edge& e : nodes[v].adj) {
        int w = e.dest;
        if(!nodes[w].visited) {
            dfs_scc2(w,st,sccs,currCount);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
        }
        if (nodes[w].inStack) {
            nodes[v].low = min(nodes[v].low, nodes[w].num);
        }
    }
    if (nodes[v].low == num) {
        list<int> scc;
        int w;
        do {
            w = st.top();
            st.pop();
            nodes[w].inStack = false;
            scc.push_front(w);
        } while (nodes[w].num != num);
        sccs.push_back(scc);
    }
}

void Graph::dfs_articulation_points(int v, int &order, list<int> &l) {
    nodes[v].visited = true;
    nodes[v].num = nodes[v].low = order++;
    int children = 0;
    bool articulation = false;
    for (Edge e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited) {
            children++;
            dfs_articulation_points(w, order, l);
            nodes[v].low = min(nodes[v].low, nodes[w].low);
            if (nodes[w].low >= nodes[v].num) {
                articulation = true;
            }
        }
        else {
            nodes[v].low = min(nodes[v].low, nodes[w].num);
        }
    }
    if ((nodes[v].num == 1 && children > 1) || (nodes[v].num > 1 && articulation)) {
        l.push_front(v);
    }
}

// ----------------------------------------------------------
// Exercicio 1: DFS e grafos bipartidos
// ----------------------------------------------------------

// TODO
bool Graph::bipartite() {
    for (int i = 1; i <= n; i++) {
        nodes[i].visited = false;
    }
    coloreddfs(1, "red");
    for (int i = 2; i <= n; i++) {
        if (!nodes[i].visited) {
            coloreddfs(i, false);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (Edge e : nodes[i].adj) {
            int w = e.dest;
            if (nodes[i].color == nodes[w].color) {return false;}
        }
    }
    return true;
}

// ----------------------------------------------------------
// Exercicio 2.a: Contando componentes fortemente conexos.
// ----------------------------------------------------------

// TODO
int Graph::countSCCs() {
    for (Node& node : nodes) {
        node.visited = false;
        node.inStack = false;
        node.low = 0;
        node.num = 0;
    }
    int count = 0;
    int order = 1;
    stack<int> stack;
    for (int v = 1; v <= n; v++) {
        if (!nodes[v].visited) {
            count += dfs_count_scc(v, order, stack);
        }
    }
    return count;
}

// ----------------------------------------------------------
// Exercicio 2.b: Listando componentes fortemente conexos
// ----------------------------------------------------------

// TODO
list<list<int>> Graph::listSCCs() {
    list<list<int>> answer;
    stack<int> st;
    int currCount = 1;
    for (int i = 1; i < n; i ++) {
        nodes[i].visited = false;
        nodes[i].inStack = false;
    }
    for (int i = 1; i <= n; i++)
        if(!nodes[i].visited) {
            dfs_scc2(i,st,answer,currCount);
        }
    return answer;
}

// ----------------------------------------------------------
// Exercicio 3: Pontos de articulação
// ----------------------------------------------------------

// TODO
list<int> Graph::articulationPoints() {
    list<int> answer;
    for (Node &node : nodes) {
        node.visited = false;
        node.parent = -1;
        node.low = 0;
        node.num = 0;
    }
    int order = 1;
    for (int v = 1; v <= n; v++)
        if (!nodes[v].visited)
            dfs_articulation_points(v, order, answer);
    return answer;
}
