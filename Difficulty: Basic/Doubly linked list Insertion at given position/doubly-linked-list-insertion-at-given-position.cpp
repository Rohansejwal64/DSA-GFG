/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

// Function to insert a new node at given position in doubly linked list.
class Solution {
  public:
    // Function to insert a new node at given position in doubly linked list.
    Node *addNode(Node *head, int pos, int data) {
        // code here
        Node* temp=head;
        int count=0;
        while(temp!=NULL && count<pos){
            temp=temp->next;
            count++;
        }
        if(temp==NULL) return head;
        Node* newnode=new Node(data);
        if(temp->next == NULL){
            temp->next=newnode;
            newnode->prev=temp;
        }
        else{
            newnode->next=temp->next;
            temp->next->prev=newnode;
            temp->next=newnode;
            newnode->prev=temp;
            
        }
        return head;
    }
};