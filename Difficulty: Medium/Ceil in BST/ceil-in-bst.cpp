/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};  */

int findCeil(Node* root, int input) {
    // Your code here
    Node* temp=root;
    int ans=-1;
    while(temp){
        if(temp->data>input){
            ans=temp->data;
            temp=temp->left;
        }
        else if(temp->data<input){
            temp=temp->right;
        }
        else{
            ans=temp->data;
            return ans;
        }
        
    }
    return ans;
}