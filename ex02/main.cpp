#include "MutantStack.hpp"

#include <iostream>
#include <list>

int main()
{
    MutantStack<int> stack;

    stack.push(5);
    stack.push(17);

    std::cout << stack.top() << std::endl;

    stack.pop();

    std::cout << stack.size() << std::endl;

    stack.push(3);
    stack.push(5);
    stack.push(737);
    stack.push(0);

    MutantStack<int>::iterator it = stack.begin();
    MutantStack<int>::iterator ite = stack.end();

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    return 0;
}