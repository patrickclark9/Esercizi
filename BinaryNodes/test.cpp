#include "BinaryTree.hpp"
#include "zeroOne.hpp"

int main()
{
    BinaryTree<int> b;
    ZeroOne<int> l;
    Node<int> *n1 = new Node<int>(0);
    Node<int> *n2 = new Node<int>(1);
    Node<int> *n3 = new Node<int>(1);
    Node<int> *n4 = new Node<int>(0);
    Node<int> *n5 = new Node<int>(0);

    b.insertRoot(n1);
    b.insertNodeSx(n2, n1);
    b.insertNodeDx(n3, n1);
    b.insertNodeSx(n4, n2);
    b.insertNodeDx(n5, n2);
    l.isZeroOneTree(b);

    return 0;
    system("PAUSE");
}