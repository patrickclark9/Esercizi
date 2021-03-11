#include "BinaryTree.hpp"
#include "list.hpp"

using std::cout;
using std::endl;
template <class V>
class Leaf : public BinaryTree<V>
{
public:
    int nrOfLeaf(const BinaryTree<V> &L)
    {
        Coda<Node<V> *> q;
        int count = 0;
        q.inCoda(L.getRoot());
        while (q.codaVuota() == false)
        {
            Node<V> *temp = q.getFront();
            q.fuoriCoda();

            if (L.isLeaf(temp) == true)
            {
                count++;
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
        cout << "there are " << count << " leaves" << endl;
    }

    int nodesAtLevel(const BinaryTree<int> &L, int rlevel)
    {
        Coda<Node<V> *> q;
        int clevel = 0;
        q.inCoda(L.getRoot());
        Coda<Node<V> *> resultq;
        while (q.codaVuota() == false)
        {
            Node<V> *temp = q.getFront();
            q.fuoriCoda();

            if (clevel == rlevel)
            {
                resultq.inCoda(temp);
            }
            else
            {
                clevel++;

                q.flushQueue();

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
        cout << "there are " << resultq.getSize() << " nodes in level " << rlevel << endl;
        return resultq.getSize();
    }

    LinkedList<V> averageAtLevel(const BinaryTree<V> &L)
    {
        Coda<Node<V> *> q;
        q.inCoda(L.getRoot());
        LinkedList<int> res;

        while (q.codaVuota() == false)
        {
            int sum = 0;
            int count = 0;
            Coda<Node<V> *> tempr;
            while (q.codaVuota() == false)
            {

                Node<V> *temp = q.getFront();
                q.fuoriCoda();
                sum = sum + temp->getValue();
                count++;

                if (temp->getLeft() != NULL)
                {
                    tempr.inCoda(temp->getLeft());
                }
                if (temp->getRight() != NULL)
                {
                    tempr.inCoda(temp->getRight());
                }
            }
            q = tempr;
            res.insert((sum / count), res.begin());
        }
        cout << "The result list is " << res << endl;
        return res;
    }
};