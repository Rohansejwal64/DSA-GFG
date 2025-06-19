// User function Template for C++

/*class Node {
public:
    int data;
    Node* next;

    // Default constructor
    Node()
    {
        data = 0;
        next = NULL;
    }

    // Parameterised Constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};*/

class Solution {
  public:
    Node* constructLL(vector<int>& arr) {
        // code here
        Node* head=NULL;
        Node* temp=new Node(arr[0]);
        head=temp;
        for(int i=1;i<arr.size();i++){
            Node* newnode=new Node(arr[i]);
            temp->next=newnode;
            temp=newnode;
        }
        return head;
    }
};