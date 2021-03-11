#include <string>
#include <iostream>
#include "string.hpp"

int main()
{
    eostring n;
    std::string s1 = "ciao";
    std::string s2 = "buonasera";
    std::string s3 = "latte";
    std::string s4 = "caffett";
    std::string s5 = "carlot";
    std::string s6 = "pari";
    char c;

    n.insertString(s1);
    n.insertString(s2);
    n.insertString(s3);
    n.insertString(s4);
    n.insertString(s5);
    n.insertString(s6);
    n.removeEvenC();
    n.nrEven();
    n.printOdd();
    n.printEven();

    return 0;
}