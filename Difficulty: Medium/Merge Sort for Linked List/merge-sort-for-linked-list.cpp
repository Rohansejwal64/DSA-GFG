/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* Merge(Node* l1,Node* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        Node* dummy=new Node(0);
        Node* tail=dummy;
        while(l1 && l2){
            if(l1->data<l2->data){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        tail->next =(l1)?l1:l2;
        return dummy->next;
        
    }
    Node* mergeSort(Node* head) {
        // your code here
        if(head->next==NULL){
            return head;
        }
        Node* slow=head;
        Node* fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* right=slow->next;
        slow->next=NULL;
        Node* left=mergeSort(head);
        right=mergeSort(right);
       return Merge(left,right);
        
    }
};