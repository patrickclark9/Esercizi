#include "BinaryTree.hpp"
using std::cout;
using std::endl;

template <class V>
class Height : public BinaryTree<V>
{
public:
    int heightofTree(V val, const BinaryTree<V> &L)
    {
        Node<V> *temp = new Node<V>;
        Node<V> *node = new Node<V>;
        node = L.search(val);
        Coda<Node<V> *> q;
        q.inCoda(node);
        int height = 0;
        int nodeCount;

        while (q.codaVuota() == false)
        {
            nodeCount = q.getSize();
            if (nodeCount == 0)
            {
                return height;
            }
            height++;
            while (nodeCount > 0)
            {
                temp = q.getFront();
                q.fuoriCoda();
                nodeCount--;
                if (temp->getLeft() != NULL)
                {
                    q.inCoda(temp->getLeft());
                }
                if (temp->getRight() != NULL)
                {
                    q.inCoda(temp->getRight());
                }
            }
        }
        std::cout << " tree height is  " << height << std::endl;
        return height;
    }

    bool isHeightBalanced(const BinaryTree<V> &L)
    {
        if (L.isEmpty() == true)
        {
            std::cout << "The tree is balanced in height" << std::endl;
            return true;
        }

        int diff = heightofTree(L.getRoot()->getLeftVal(), L) - heightofTree(L.getRoot()->getRightVal(), L);

        if (diff >= 0 && diff <= 1)
        {
            std::cout << "The tree is balanced in height" << std::endl;
            return true;
        }
        std::cout << "the tree is not balanced in height" << std::endl;
        return false;
    }

    bool completeNodes(const BinaryTree<V> &L)
    {
        int countNodes = 0;
        bool flag;
        Coda<Node<V> *> q;
        q.inCoda(L.getRoot());

        while (q.codaVuota() == false)
        {
            Node<V> *temp = q.getFront();
            q.fuoriCoda();

            if (L.isLeaf(temp) == false)
            {
                if (temp->getLeft() != NULL && temp->getRight() != NULL)
                {
                    flag = true;
                } else 
                {
                cout << "At least 1 non-leaf node is not complete" << endl;
                return false;
                }
            }
            if (temp->getLeft() != NULL)
            {
                q.inCoda(temp->getLeft());
            }
            if (temp->getRight() != NULL)
            {
                q.inCoda(temp->getRight());
            }
        }
        cout << "all non-leaf nodes are complete" << endl;
        return flag;
    }
};