Design queue structure based on array:
N:the queue size
front = -1
rear = -1

1.Non-circular queue（最多使用N個空間）
  (1) Full condition:   rear == N-1
  (2) Empty condition:  front== rear
  Problem:there may be available space when QueueFull is true.

2.Cicular queue（最多使用(N-1)個空間）
  Concept:q[0] comes after q[N-1]
  (1) Full condition:   front==(rear+1)%N && (rear==N-1 && front==-1)
  (2) Empty condition:  front== rear
  Problem:队列滿了，浪費一個空格沒有使用，若再加入一個項目時，Rear等於0，也就是Front等於Rear，如此無法分辨此時佇列是空的還是滿的。因此，環形佇列必須浪費一個空格。當Front等於Rear時，環形佇列為空的。當(Rear+1) Mod N等於Front時，環形佇列為已滿。
