#include <string>
#include "list.hpp"

using namespace std;

class eostring
{
private:
    LinkedList<string> even;
    LinkedList<string> odd;
    int evenCount;

public:
    eostring()
    {
        evenCount = 0;
    }
    void insertString(string s)
    {
        if (s.length() % 2 == 0)
        {
            even.insert(s, even.begin());
            evenCount++;
        }
        else
        {
            odd.insert(s, odd.begin());
        }
    }

    void removeString(string s)
    {
        if (even.isPresent(even, s))
        {
            even.erase(even.getNode(even, s));
            evenCount--;
        }
        else if (odd.isPresent(odd, s))
        {
            odd.erase(even.getNode(odd, s));
        }
    }

    void removeEvenC()
    {
        char c = 'c';
        ListNode<string> *str = new ListNode<string>;
        str = even.begin();
        while (!even.end(str))
        {
            if (even.read(str).at(0) == c)
            {
                even.erase(str);
                evenCount--;
            }
            str = str->getNext();
        }
    }

    int nrEven()
    {
        std::cout << "there are"
                  << " " << evenCount << " "
                  << "even strings" << std::endl;
        return evenCount;
    }

    void printOdd()
    {
        ListNode<string> *node = new ListNode<string>;
        ListNode<string> *temp = new ListNode<string>;
        LinkedList<string> List;
        node = odd.begin();
        temp = List.begin();
        List.insert(node->getValue(), List.begin());
        node = node->getNext();
        while (!odd.end(node))
        {
            if (List.read(temp).length() < odd.read(node).length())
            {
                List.insert(node->getValue(), temp->getPrev());
            }
            else
            {
                List.insert(node->getValue(), node->getNext());
            }
            node = node->getNext();
            temp = temp->getNext();
        }
        std::cout << "list is: "
                  << " " << odd << std::endl;
    }

    void printEven()
    {
        std::cout << "list is " << even << std::endl;
    }
};