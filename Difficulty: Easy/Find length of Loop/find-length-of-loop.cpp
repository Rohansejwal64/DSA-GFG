/*
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution {
  public:
    // Function to find the length of a loop in the linked list.
    int countNodesinLoop(Node *head) {
        // Code here
        Node* slow = head;
    Node* fast = head;
    int ans=0;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Cycle detected
            slow = slow->next;
            ans=1;
            

            // Phase 2: Find the starting node of the cycle
            while (slow != fast) {
                slow = slow->next;
                ans++;
            }

            return ans;
        }
    }
    return ans;
    }
};