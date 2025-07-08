/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
  bool isleaf(Node* root){
      if(root!=NULL && root->left==NULL && root->right==NULL) return true;
      return false;
  }
  void leftB(Node* root,vector<int>& ans){
      if(root==NULL) return;
      if(!isleaf(root)) ans.push_back(root->data);
      if(root->left) leftB(root->left,ans);
      else if(root->right) leftB(root->right,ans);
      
  }
  void leaf(Node* root,vector<int>& ans){
      if(root==NULL) return;
      if(isleaf(root)) {
          ans.push_back(root->data);
          return;
      }
      leaf(root->left,ans);
      leaf(root->right,ans);
      
  }
  void rightB(Node* root,vector<int>& ans){
      if(root==NULL || isleaf(root)) return;
       
      if(root->right) rightB(root->right,ans);
      else if(root->left) rightB(root->left,ans);
      ans.push_back(root->data);
      
  }
  
    vector<int> boundaryTraversal(Node *root) {
        // code here
        
        vector<int> ans;
       if(!isleaf(root))  ans.push_back(root->data);
        leftB(root->left,ans);
        leaf(root,ans);
        rightB(root->right,ans);
        return ans;
    }
};