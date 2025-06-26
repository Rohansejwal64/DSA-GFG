/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

class Solution {
  public:
    // Function which returns the  root of the flattened linked list.
    Node* Merge(Node* l1,Node* l2){
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        Node* dummy=new Node(0);
        Node* tail=dummy;
        while(l1 && l2){
            if(l1->data<l2->data){
                tail->bottom=l1;
                l1=l1->bottom;
            }
            else{
                tail->bottom=l2;
                l2=l2->bottom;
            }
            tail=tail->bottom;
        }
        tail->bottom =(l1)?l1:l2;
        return dummy->bottom;
        
    }
    Node *flatten(Node *root) {
        // Your code here
        Node* head=root;
        if(head->next==NULL){
            return head;
        }
        Node* down=head;
        Node* right=flatten(head->next);
        down->next=NULL;
        return Merge(down,right);
    }
};