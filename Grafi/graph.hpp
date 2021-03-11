#include <iostream>
#include <vector>
#include "list copy.hpp"
#include "coda.hpp"
using std::vector;

template <class G>
class Node
{
    G label;
    LinkedList<Node<G> *> *adj;
    bool visited;

public:
    Node()
    {
        adj = new LinkedList<Node<G> *>;
        visited = false;
    }
    Node(G value)
    {
        label = value;
        adj = new LinkedList<Node<G> *>;
        visited = false;
    }
    LinkedList<Node<G> *> *getAdj()
    {
        return adj;
    }

    void setAdj(Node<G> *L)
    {
        adj->insert(L, adj->begin());
    }

    void setLabel(G value)
    {
        label = value;
    }

    G getLabel() const
    {
        return label;
    }

    bool isAdj(Node<G> *L)
    {
        ListNode<Node<G> *> *temp = adj->begin();
        while (!adj->end(temp))
        {
            if (L->getLabel() == adj->read(temp)->getLabel())
            {
                return true;
            }
            temp = temp->getNext();
        }
        return false;
    }

    void setVisited()
    {
        visited = true;
    }
    void setUnvisited()
    {
        visited = false;
    }
    bool isVisited()
    {
        if (visited == true)
        {
            return true;
        }
        return false;
    }
};
template <class G>
class Arc
{
private:
    Node<G> Arcs[2];

public:
    Arc(Node<G> n, Node<G> m)
    {
        Arcs[0] = n;
        Arcs[1] = m;
    }
    void insertArc(Node<G> n, Node<G> m)
    {
        Arcs[0] = n;
        Arcs[1] = m;
    }

    Node<G> getArc()
    {
        return Arcs[2];
    }
    Node<G> getFirst()
    {
        return Arcs[0];
    }
    Node<G> getSecond()
    {
        return Arcs[1];
    }
};

template <class G>
class Graph
{

private:
    int nrOfEdge;
    int nrOfNodes;
    LinkedList<Node<G> *> *nodeList;
    vector<Arc<G> > *Arcs;

public:
    Graph()
    {
        nodeList = new LinkedList<Node<G> *>;
        Arcs = new vector<Arc<G> >;
        nrOfEdge = 0;
        nrOfNodes = 0;
    }

    ~Graph()
    {
        delete nodeList;
        delete Arcs;
    }

    bool empty()
    {
        if (nodeList->empty() == true)
        {
            return true;
        }
        return false;
    }

    bool nodeFound(Node<G> *L)
    {
        ListNode<Node<G> > *temp = new ListNode<Node<G> >;
        temp = nodeList->begin();
        while (!nodeList->end(temp))
        {
            if (temp->getValue() == L)
            {
                std::cout << "List HIT" << std::endl;
                return true;
            }
            if (temp->getNext() != NULL)
            {
                temp = temp->getNext();
            }
        }
        std::cout << "List MISS" << std::endl;
        return false;
    }

    void insNode(Node<G> *L)
    {
        nrOfNodes++;
        nodeList->insert(L, nodeList->begin());
    }

    void insEdge(Node<G> *L, Node<G> *N)
    {
        Node<G> *temp = new Node<G>;
        temp = N;
        L->setAdj(temp);
        nrOfEdge++;
    }

    void removeNode(Node<G> *L)
    {
        if (L->getAdj()->empty())
        {
            ListNode<Node<G> *> *temp = nodeList->begin();
            bool flag = false;
            for (int i = 0; i < nodeList->size(); i++)
            {
                Node<G> *temp2 = temp->getValue();
                if (temp2->isAdj(L))
                {
                    std::cout << "Node is adjacent to another node: cannot delete" << std::endl;
                    flag = false;
                    break;
                }
                flag = true;
                temp = temp->getNext();
            }
            if (flag == true)
            {
                temp = nodeList->begin();
                while (!nodeList->end(temp))
                {
                    if (L->getLabel() == temp->getValue()->getLabel())
                    {
                        nodeList->erase(temp);
                        nrOfNodes--;
                        break;
                    }
                    temp = temp->getNext();
                }
            }
        }
        else
        {
            std::cout << "Node has adjacent nodes: cannot delete" << std::endl;
        }
    }

    void removeEdge(Node<G> *L, Node<G> *N)
    {
        if (!L->getAdj()->empty())
        {
            if (L->isAdj(N))
            {
                ListNode<Node<G> *> *temp = L->getAdj()->begin();
                while (!L->getAdj()->end(temp))
                {
                    if (N->getLabel() == temp->getValue()->getLabel())
                    {
                        L->getAdj()->erase(temp);
                        std::cout << "Arc Removed" << std::endl;
                        break;
                    }
                    temp = temp->getNext();
                }
            }
            else
            {
                std::cout << "Arc not Removed: Arc does not exist" << std::endl;
            }
        }
    }

    bool isReachable(Node<G> *start, Node<G> *dest)
    {
        ListNode<Node<G> *> *lnode = nodeList->begin();
        while (!nodeList)
        {
            lnode->getValue()->setUnvisited();
            lnode->getNext();
        }

        Coda<Node<G> *> q;
        Node<G> *temp = start;
        Node<G> *destination = dest;
        q.inCoda(temp);
        while (!q.codaVuota())
        {
            temp = q.getFront();
            temp->setVisited();
            q.fuoriCoda();
            ListNode<Node<G> *> *node = temp->getAdj()->begin();
            while (!temp->getAdj()->end(node))
            {
                if (node->getValue() == destination)
                {
                    std::cout << "is Reachable" << std::endl;
                    return true;
                }
                else
                {
                    if (!node->getValue()->isVisited())
                    {
                        node->getValue()->setVisited();
                        q.inCoda(node->getValue());
                    }
                    else
                    {
                        node = node->getNext();
                    }
                }
            }
        }
        std::cout << "There is no Path leading from starting node to destination node" << std::endl;
        return false;
    }
};
template <class G>
inline bool operator==(const Node<G> &N, const Node<G> &L)
{
    if (N.getLabel() == L.getLabel())
    {
        return true;
    }
    return false;
}

template <class G>
inline bool operator!=(const Node<G> &N, const Node<G> &L)
{
    if (N.getLabel() != L.getLabel())
    {
        return true;
    }
    return false;
}
