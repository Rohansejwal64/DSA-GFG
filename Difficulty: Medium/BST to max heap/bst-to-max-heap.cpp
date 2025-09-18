// User function Template for C++

/*struct Node {
    int data;
    Node *left, *right;
};*/

class Solution {
  public:
  void postorder(Node* root,vector<int> &ans, int &i){
       if(!root) return ;
       postorder(root->left,ans,i);
       postorder(root->right,ans,i);
       root->data=ans[i];
       i++;
  }
  void inorder(Node* root,vector<int> &ans){
      if(!root) return ;
      
      inorder(root->left,ans);
      ans.push_back(root->data);
      inorder(root->right,ans);
  }
    void convertToMaxHeapUtil(Node* root) {
        // Your code goes here
        vector<int> ans;
        inorder(root,ans);
        
        int i=0;
        postorder(root,ans,i);
    }
};
