#include "BinaryTree.hpp"
template <class V>
class ZeroOne
{
public:
    bool isZeroOne(const BinaryTree<V> &T)
    {
        bool flag;
        Coda<Node<V> *> q;
        q.inCoda(T.getRoot());
        while (q.codaVuota() == false)
        {
            Node<V> *temp = q.getFront();
            q.fuoriCoda();
            if (temp->getLeft() != NULL && temp->getRight() != NULL)
            {
                if (T.getRoot()->getValue() == 0)
                {

                    if (temp->getValue() == 0)
                    {
                        if (temp->getLeft()->getValue() == 1 && temp->getLeft()->getValue() == 1)
                        {
                            flag = true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else if (temp->getValue() == 1)
                    {
                        if (temp->getLeft()->getValue() == 0 && temp->getLeft()->getValue() == 0)
                        {
                            flag = true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                }
                else
                {
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

        return flag;
    }

    bool isZeroOneTree(const BinaryTree<V> &T)
    {
        bool flag;
        flag = isZeroOne(T);
        if (flag == true)
        {
            std::cout << "tree is a Zero One tree" << std::endl;
            return true;
        }
        else
        {
            std::cout << "tree is not a Zero One tree" << std::endl;
            return false;
        }
    }

    int nrOf0(const BinaryTree<V> &T)
    {
        int count0 = 0;
        Coda<Node<V> *> q;
        q.inCoda(T.getRoot());

        while (q.codaVuota() == false)
        {
            Node<V> *temp = q.getFront();
            q.fuoriCoda();

            if (temp->getLabel() == 0)
            {
                count0++;
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
        std::cout << "There are " << count0 << " "
                  << "zeros in the Tree" << std::endl;
        return count0;
    }
};