// User function Template for C++

/*struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *node = (struct node *)malloc(sizeof(struct node));

  node->data = data;

  node->left = NULL;
  node->right = NULL;
  return (node);
}*/

class Solution {
  public:
node* buildtree(vector<int>& vec){
     if (vec.size() == 0 || vec[0] == -1) {
            return NULL;
        }

        node* root = newNode(vec[0]);
        queue<node*> q;
        q.push(root);

        int i = 1;
        while (i < vec.size()) {
            node* curr = q.front();
            q.pop();

            // Left child
            if (i < vec.size() && vec[i] != -1) {
                curr->left = newNode(vec[i]);
                q.push(curr->left);
            }
            i++;

            // Right child
            if (i < vec.size() && vec[i] != -1) {
                curr->right = newNode(vec[i]);
                q.push(curr->right);
            }
            i++;
        }

        return root;
}
    void create_tree(node* &root0, vector<int>& vec) {
        // Your code goes here
        root0=buildtree(vec);
    }
};