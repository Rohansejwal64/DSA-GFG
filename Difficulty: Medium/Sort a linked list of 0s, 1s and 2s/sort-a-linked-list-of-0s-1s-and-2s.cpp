/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        // code here
        int c0=0,c1=0,c2=0;
        Node* temp=head;
        while(temp!=NULL){
            if(temp->data==0) c0++;
            if(temp->data==1) c1++;
            if(temp->data==2) c2++;
            temp=temp->next;
            
        }
        temp=head;
        while(temp!=NULL){
            if(c0){
                temp->data=0;
                c0--;
                temp=temp->next;
            }
            else if(c1){
                temp->data=1;
                c1--;
                temp=temp->next;
            }
            else{
                temp->data=2;
                c2--;
                temp=temp->next;
            }
        }
        return head;
        
    }
};