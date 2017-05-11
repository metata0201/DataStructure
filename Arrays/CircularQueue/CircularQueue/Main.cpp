#include "CircularQueue.h"
#include <iostream>

void main()
{
    CircularQueue Q;
    Q.Add(1);
    Q.Add(2);
    Q.Add(3);
    Q.Add(4);
    Q.Add(5);
    Q.Add(6);
    Q.PrintQueue();

    std::cout << "delete: " << Q.Delete() << std::endl;
    std::cout << "delete: " << Q.Delete() << std::endl;
    Q.PrintQueue();

    Q.Delete();
    Q.Delete();
    Q.Delete();
    Q.Delete();
    Q.PrintQueue();

    Q.Add(7);
    Q.Add(8);
    Q.Add(9);
    Q.PrintQueue();
}