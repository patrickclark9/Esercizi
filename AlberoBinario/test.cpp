
#include "zeroOne.hpp"
#include "Leaf.hpp"
#include "Height.hpp"
int main()
{
    BinaryTree<int> b;
    Leaf<int> l;
    l.insertRoot(4);

    b.insertRoot(1);
    b.insertNodeSx(2, 1);
    b.insertNodeDx(5, 1);
    b.insertNodeSx(4, 2);
    b.insertNodeSx(7, 4);
    l.nodesAtLevel(b, 1);
    l.averageAtLevel(b);
    b.deleteTree(1);

    return 0;
    system("PAUSE");
}