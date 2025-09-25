class Node {
  public:
    int data;
    Node* next;

    Node(int new_data) {
        data = new_data;
        next = nullptr;
    }
};

class myQueue {
    
    

  public:
  
  
  Node *head, *tail;
  int s;
    myQueue() {
        // Initialize your data members
        head=tail=NULL;
        s=0;
    }

    bool isEmpty() {
        // check if the queue is empty
        if(s==0) return true;
        return false;
    }

    void enqueue(int x) {
        // Adds an element x at the rear of the queue
        Node *newnode=new Node(x);
       if(s==0){
           
           tail=head=newnode;
       }
       else{
        tail->next=newnode;
        tail=newnode;
       }
       
        s++;
        
    }

    void dequeue() {
        // Removes the front element of the queue
        if(s==0) return;
        Node *temp=head;
        head=head->next;
        s--;
        temp->next=NULL;
        delete temp;
    }

    int getFront() {
        // Returns the front element of the queue
        // If queue is empty, return -1
        if(s==0) return -1;
        return head->data;
    }

    int size() {
        // Returns the current size of the queue.
        return s;
    }
};
