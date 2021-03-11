#include "Leaf.hpp"

int main()
{
    Ntree<int> l;
    Leaf<int> b;

    l.insertRoot(1);
    l.insertChild(2, 1);
    l.insertSibling(3, 2);
    l.insertSibling(4, 3);
    l.insertChild(5, 2);
    b.nodesAtLevel(l, l.getRoot(), 0, 1, 0);
    b.nrOfLeaf(l);

    return 0;
}