////
//  grid.hpp
//  Esercizio
//
//  Created by Patrick Clark on 04/02/21.
//

#ifndef grid_hpp
#define grid_hpp
#define MAX 20

#include <iostream>
#include <list>
const int NIL = -1;

template <class V>
class cell
{
private:
    int x;
    int y;
    int alive; // alive->0 = dead, alive->1 = alive;
    int val;
public:
    void setX(int n)
    {
        x = n;
    }
    void setY(int n)
    {
        y = n;
    }
    void setVal(int v)
    {
        val = v;
    }
    int getVal()
    {
        return val;
    }
    cell()
    {
        x = NIL;
        y = NIL;
        alive = 0;
    }
    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }
    bool isAlive()
    {
        if (alive == 0)
        {
            return false;
        }
        return true;
    }
    
    void setAlive()
    {
        alive = 1;
    }
    
    
};

template <class V>
class Grid
{
private:
    std::list<cell<V> > list1;
    cell<V> elements[MAX][MAX];
public:
    void insertGrid(cell<V> & n)
    {
        if(n.getX() != NIL && n.getY() != NIL)
        {
            n.setAlive();
            cell<V> temp = n;
            int i = n.getX();
            int j = n.getY();
            elements[i][j] = temp;
        } else {
            std::cout<< "not empty"<< std::endl;
        }
    }
    
    void insertList()
    {
        typename std::list<cell<V> >::iterator it;
        it = list1.begin();
        for (int i = 0; i<MAX; i++)
        {
            for (int j = 0; j< MAX; j++)
            {
                cell<V> temp = elements[i][j];
                if (temp.isAlive() == true)
                {
                  
                   list1.insert(it,temp);
                    it++;
                }
            }
        }
    }
  
};
#endif