Design queue structure based on array:
N:the queue size
front = -1
rear = -1

1.Non-circular queue�����ʹ��N�����g��
  (1) Full condition:   rear == N-1
  (2) Empty condition:  front== rear
  Problem:there may be available space when QueueFull is true.

2.Cicular queue�����ʹ��(N-1)�����g��
  Concept:q[0] comes after q[N-1]
  (1) Full condition:   front==(rear+1)%N && (rear==N-1 && front==-1)
  (2) Empty condition:  front== rear
  Problem:���НM�ˣ����Mһ���ո�]��ʹ�ã����ټ���һ���Ŀ�r��Rear���0��Ҳ����Front���Rear����˟o���ֱ�˕r�����ǿյ�߀�ǝM�ġ���ˣ��h�΁��б�����Mһ���ո񡣮�Front���Rear�r���h�΁��О�յġ���(Rear+1) Mod N���Front�r���h�΁��О��ѝM��
