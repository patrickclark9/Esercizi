#include "Ntree.hpp"
#include "list.hpp"

using std::cout;
using std::endl;
template <class T>
class Leaf
{
public:
    int nrOfLeaf(const Ntree<T> &L)
    {
        Coda<Node<T> *> q;
        int count = 0;
        q.inCoda(L.getRoot());
        while (q.codaVuota() == false)
        {
            Node<T> *temp = q.getFront();
            q.fuoriCoda();

            if (L.isLeaf(temp) == true)
            {
                count++;
            }

            if (temp->getFirst() != NULL)
            {
                q.inCoda(temp->getFirst());
            }
            if (temp->getNext() != NULL)
            {
                q.inCoda(temp->getNext());
            }
        }
        cout << endl
             << "there are " << count << " leaves" << endl;
    }

    void nodesAtLevel(const Ntree<T> &L, Node<T> *node, int clevel, int rlevel, int count)
    {
        if (node == NULL)
        {
            return;
        }
        if (clevel == rlevel)
        {
            cout << " " << node->getValue() << " ";
        }
        nodesAtLevel(L, node->getFirst(), clevel + 1, rlevel, count);
        nodesAtLevel(L, node->getNext(), clevel, rlevel, count);
    }

}
/*
    LinkedList<V> averageAtLevel(const Ntree<V> &L)
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
            res.insert((sum / count), res.last());
        }
        cout << "The result list is " << res << endl;
        return res;
    }
    */
;