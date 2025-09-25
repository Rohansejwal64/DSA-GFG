class myQueue {

  public:
  int *arr;
  int front,rear;
  int size;
    myQueue(int n) {
        // Define Data Structures
        size=n;
        arr=new int[size];
        front=rear=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(rear==front) return true;
        return false;
    }

    bool isFull() {
        // check if the queue is full
        if(rear==size) return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue.
        if(rear==size) return;
        arr[rear]=x;
        rear++;
    }

    void dequeue() {
        // Removes the front element of the queue.
        if(front==rear) return;
        for(int i=front+1;i<=rear-1;i++){
            arr[i-1]=arr[i];
        }
        rear--;
    }

    int getFront() {
        // Returns the front element of the queue.
        if(front==rear) return -1;
        return arr[front];
    }

    int getRear() {
        // Return the last element of queue
        if(front==rear) return -1;
        return arr[rear-1];
    }
};