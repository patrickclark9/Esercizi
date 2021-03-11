#include <stdio.h>
#include "grid.hpp"

int main()
{
    cell<int> n1,n2;
    Grid<int> grid;
    
    n1.setX(2);
    n1.setY(3);
    n2.setX(5);
    n2.setY(6);
    n1.setVal(2);
    n2.setVal(3);
    
    grid.insertGrid(n1);
    grid.insertGrid(n2);
    grid.insertList();
    
    
    
    
    
    
    return 0;
}
