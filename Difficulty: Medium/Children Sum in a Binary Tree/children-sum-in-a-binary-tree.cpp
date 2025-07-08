/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to check whether all nodes of a tree have the value
    // equal to the sum of their child nodes.
    int isSumProperty(Node *root) {
        // Add your code here
        if(root==NULL ) return 1;
        if(root->left && root->right && root->data !=root->left->data+root->right->data){
            return 0;
            
            
        }
        else if(root->left && root->right==NULL && root->data!=root->left->data){
            return 0;
            
        }
        else if(root->left==NULL && root->right && root->data!=root->right->data){
            return 0;
        }
        int l=isSumProperty(root->left);
        int r=isSumProperty(root->right);
        if(l==0 || r==0) return 0;
        return 1;
        
    }
};