/* class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
}; */

class myStack {

  public:
  Node *head;
  int s;
    myStack() {
        // Initialize your data members
        head=NULL;
        s=0;
    }

    bool isEmpty() {
        // check if the stack is empty
        if(head==NULL) return true;
        return false;
    }

    void push(int x) {
        // Adds an element x at the top of the stack
        Node *newnode= new Node(x);
        newnode->next=head;
        head=newnode;
        s++;
    }

    void pop() {
        // Removes the top element of the stack
        if(head==NULL) return;
        Node *temp=head;
        head=head->next;
        temp->next=NULL;
        s--;
        delete temp;
    }

    int peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(s==0) return -1;
        return head->data;
    }

    int size() {
        // Returns the current size of the stack.
        return s;
    }
};