#include "HashMap.hpp"

int main()
{
    HashMap<int, int> m;

    m.insertNode(1, 5);
    m.insertNode(2, 7);
    m.insertNode(3, 9);
    m.insertNode(4, 4);
    m.remove(4);
    m.display();

    return 0;
    system("PAUSE");
}