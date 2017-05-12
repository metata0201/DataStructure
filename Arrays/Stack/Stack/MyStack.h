#include <iostream>

#define MAX_STACK_SIZE 10

template <class T>
class MyStack
{
public:
    MyStack(int maxStackSize = MAX_STACK_SIZE)
    {
        pStack = new T[maxStackSize];
        size = maxStackSize;
        top = -1;
    }

    ~MyStack()
    {
        if (pStack)
        {
            delete[]pStack;
            pStack = NULL;
        }
    }

    bool IsFull()
    {
        return (top == size - 1);
    }

    bool IsEmpty()
    {
        return (top == -1);
    }

    void Push(T x)
    {
        if (IsFull())
        {
            std::cout << "The stack is full! you can't push:" << x << std::endl;
            return;
        }

        top++;
        pStack[top] = x;
    }

    T Pop()
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty,it can't pop anything!" << std::endl;
            return 0;
        }

        return pStack[top--];
    }

    T TopVal()
    {
        if (IsEmpty())
        {
            std::cout << "The stack is empty!" << std::endl;
            return 0;
        }

        return pStack[top];
    }

private:
    int top, size;
    T *pStack;
};