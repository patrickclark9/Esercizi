#include <iostream>
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
std::ostream &operator<<(std::ostream &os, const Node<G> *N)
{
    os << "[";
    os << N->getLabel();
    os << "]"
       << "->";
    return os;
}