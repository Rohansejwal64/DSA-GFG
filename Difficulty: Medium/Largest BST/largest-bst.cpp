/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class info{
    public: 
    int maxi;
    int mini;
    bool isBST;
    int size;
    
};

class Solution{
    public:
    info solve(Node* root,int &ans){
        if(root==NULL){
            return {INT_MIN,INT_MAX,true,0};
        }
        info left=solve(root->left,ans);
        info right=solve(root->right,ans);
        info curr;
        curr.size=left.size+right.size+1;
        curr.maxi=max(root->data,right.maxi);
        curr.mini=min(root->data,left.mini);
        if(left.isBST && right.isBST && (root->data>left.maxi && root->data<right.mini)){
            curr.isBST=true;
            ans=max(ans,curr.size);
        }
        else{
            curr.isBST=false;
        }
        return curr;
    
}
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    
    int largestBst(Node *root)
    {
    	//Your code here
    	int ans=0;
    	solve(root,ans);
    	return ans;
    }
};
