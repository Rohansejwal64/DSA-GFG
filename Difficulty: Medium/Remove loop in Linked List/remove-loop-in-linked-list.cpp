/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        // code here
        Node* slow = head;
    Node* fast = head;

    // Phase 1: Detect cycle using Floyd's algorithm
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow=head;

            // Phase 2: Find the starting node of the cycle
            while (slow!= fast) {
                slow = slow->next;
                fast=fast->next;
                
            }
            
            Node* temp=slow;
            while(temp->next!=slow){
                temp=temp->next;
            }
            temp->next=NULL;
            break;
        }
    }
    }
};