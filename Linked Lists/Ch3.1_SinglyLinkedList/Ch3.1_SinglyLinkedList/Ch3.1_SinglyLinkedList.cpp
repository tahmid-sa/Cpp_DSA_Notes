#include <iostream>

#include "intSLList.h"

using namespace std;

int main()
{
    // Creating 2 nodes
    intSLLNode* p = new intSLLNode(10);
    p->next = new intSLLNode(8);

    // Creating a linked list
    intSLList list;
    list.addToHead(1);
    list.addToTail(2);

    return 0;
}