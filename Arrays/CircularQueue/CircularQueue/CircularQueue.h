#define DEFAULT_SIZE 6

class CircularQueue
{
public:
    CircularQueue(int maxQueueSize=DEFAULT_SIZE);
    ~CircularQueue();
    bool IsFull();
    bool IsEmpty();
    void Add(int item);
    int Delete();
    void PrintQueue();

private:
    int front, rear;
    int qSize;
    int *pQueue;
};