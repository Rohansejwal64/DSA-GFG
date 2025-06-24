/* Link list Node
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
  Node* merge(Node* list1, Node* list2){
    Node* prv=list1;
            Node* curr=list1->next;
            Node* temp=list2;
            while(curr!=NULL && temp!=NULL){
                if(temp->data>=prv->data && temp->data<=curr->data){
                    Node* insert=temp;
                    temp=temp->next;
                    prv->next=insert;
                    insert->next=curr;
                    prv=prv->next;
                    }
                    else{
                        prv=curr;
                        curr=curr->next;
                    }
            }
            if(curr==NULL){
                prv->next=temp;
            }
            return list1;
            }
    Node* sortedMerge(Node* list1, Node* list2) {
        // code here
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->data<=list2->data){
            return merge(list1,list2);
             }
             else{
                return merge(list2,list1);
             }
              }
        
    
};