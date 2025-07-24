// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int input) {
        // Code here
         Node* temp=root;
    int ans=-1;
    while(temp){
        if(temp->data>input){
            temp=temp->left;
        }
        else if(temp->data<input){
            ans=temp->data;
            temp=temp->right;
        }
        else{
            ans=temp->data;
            return ans;
        }
        
    }
    return ans;
    }
};