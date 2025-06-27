// User function Template for C++

/* a Node of the doubly linked list
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
  Node(int x) { data = x; next = prev = NULL; }
}; */

class Solution {
  public:
   void deleteAllOccurOfX(Node** head_ref, int x) {
    Node* dummy = new Node;
    dummy->data = 0;
    dummy->next = *head_ref;
    dummy->prev = NULL;
    if (*head_ref) (*head_ref)->prev = dummy;

    Node* temp = dummy;
    while (temp && temp->next) {
        if (temp->next->data == x) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            if (toDelete->next) {
                toDelete->next->prev = temp;
            }
            delete toDelete;
        } else {
            temp = temp->next;
        }
    }

    *head_ref = dummy->next;
    if (*head_ref) (*head_ref)->prev = NULL;
    delete dummy;
}
};