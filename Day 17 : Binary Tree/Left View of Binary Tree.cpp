

/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> solve(vector<int> &res, int lvl, Node *root){
    if(root==NULL) return {};
    if(lvl == res.size()) res.push_back(root->data);
    solve(res, lvl+1, root->left);
    solve(res, lvl+1, root->right);
    return res;
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> res;
  return solve(res, 0, root);
   
}
