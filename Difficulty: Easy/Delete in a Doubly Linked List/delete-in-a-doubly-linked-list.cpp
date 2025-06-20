/* Structure of Node
class Node {
  public:
    int data;
    Node *next;
    Node *prev;

    Node(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to delete a node at given position.
    Node* deleteNode(Node* head, int x) {
        // Your code here
        if(x==1){
            Node* temp=head;
            head=head->next;
            temp->next->prev=NULL;
            temp->next=NULL;
            return head;
        }
        Node* prv=NULL;
        Node* curr=head;
        int count=1;
        while(curr!=NULL && count<x ){
            prv=curr;
            curr=curr->next;
            count++;
        }
        prv->next=curr->next;
        if(curr->next) curr->next->prev=prv;
        curr->next=NULL;
        curr->prev=NULL;
        delete curr;
        return head;
    }
};