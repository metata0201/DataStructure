#include "CircularQueue.h"
#include <iostream>

CircularQueue::CircularQueue(int maxQueueSize)
{
    front = -1;
    rear  = -1;
    qSize = maxQueueSize;

    pQueue = new int[qSize];
    memset(pQueue, 0, sizeof(int)*qSize);
}

CircularQueue::~CircularQueue()
{
    if (pQueue)
    {
        delete []pQueue;
        pQueue = NULL;
    }
}

bool CircularQueue::IsFull()
{
    // don't forget the special condition:'rear==qSize-1 && front==-1'
    if (front == (rear+1)%qSize || (rear==qSize-1 && front==-1))
    {
        return true;
    }
    return false;
}

bool CircularQueue::IsEmpty()
{
    if (front == rear)
    {
        return true;
    }
    return false;
}

void CircularQueue::Add(int item)
{
    // whether the queue is full
    if (IsFull())
    {
        std::cout << "The queue is full!" << std::endl;
        return;
    }

    rear = (rear + 1) % qSize;
    pQueue[rear] = item;
}

int CircularQueue::Delete()
{
    // whether the queue is empty
    if (IsEmpty())
    {
        std::cout << "The queue is empty!" << std::endl;
        return -1;
    }

    front = (front + 1) % qSize;
    return pQueue[front];
}

void CircularQueue::PrintQueue()
{
    if (IsEmpty())
    {
        std::cout << "The queue is empty!" << std::endl;
        return;
    }

    std::cout << "front: " << front << std::endl;
    std::cout << "rear: " << rear << std::endl;
    for (int i = 0; i < qSize; i++)
    {
        if (i == front)
        {
            std::cout << pQueue[i] << "<----front " << std::endl;
        }
        else if (i == rear)
        {
            std::cout << pQueue[rear] << "<----rear " << std::endl;
        }
        else
        {
            std::cout << pQueue[i] << std::endl;
        }
    }
}