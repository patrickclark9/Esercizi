#include "list.hpp"
int main()
{
    LinkedList<int> l1;
    int x = 1;
    int y = 2;
    l1.insert(x, l1.begin());
    l1.insert(y, l1.last());
    l1.isPresent(l1, 2);
    l1.isPresent(l1, 4);
    l1.getNode(l1, 2);
    l1.getNode(l1, 4);

    std::cout << "List is:" << l1 << std::endl;

    return 0;
}
