/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }

};
*/

class Solution {
  public:

    Node *removeDuplicates(struct Node *head) {
        // Your code here
         if (!head) return head;  // Edge case: empty list
        
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->data == curr->next->data) {
                // Duplicate node found
                Node* temp = curr->next;
                curr->next = temp->next;
                if (temp->next) temp->next->prev = curr;
                delete temp; // Free memory
            } else {
                curr = curr->next;
            }
        }
        return head;
        
    }
};