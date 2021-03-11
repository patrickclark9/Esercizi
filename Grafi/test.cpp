#include "graph.hpp"

int main()
{
    Graph<int> g;
    Node<int> e1(1);
    Node<int> e2(2);
    Node<int> e3(3);
    Node<int> e4(4);

    g.insNode(e1);
    g.insNode(e2);
    g.insNode(e3);
    g.insNode(e4);

    g.insEdge(e1, e2);
    g.insEdge(e3, e4);
    g.insEdge(e2, e4);
    g.insEdge(e2, e3);
    g.removeNode(e4);
    g.removeEdge(e2, e3);
    g.isReachable(e1, e3);
    g.removeEdge(e1, e2);

    return 0;
}