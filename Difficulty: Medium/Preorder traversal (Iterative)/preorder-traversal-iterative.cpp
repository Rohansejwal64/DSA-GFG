// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};
*/
class Solution {
  public:
    vector<int> preOrder(Node* root) {
        // code here
        stack<Node*> s;
        vector<int> ans;
        
    
        s.push(root);
        while(!s.empty()){
            Node* curr=s.top();
            s.pop();
            ans.push_back(curr->data);
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
            
        }
        return ans;
    }
};