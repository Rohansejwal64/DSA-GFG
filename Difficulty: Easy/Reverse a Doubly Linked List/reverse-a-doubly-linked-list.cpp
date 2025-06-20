/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    DLLNode* reverseDLL(DLLNode* head) {
        // Your code here
        DLLNode* back=NULL;
        DLLNode* curr=NULL;
        DLLNode* frwd=head;
        while(frwd!=NULL){
            back=curr;
            curr=frwd;
            frwd=frwd->next;
            curr->next=back;
            curr->prev=frwd;
        }
        head=curr;
        return head;
    }
};