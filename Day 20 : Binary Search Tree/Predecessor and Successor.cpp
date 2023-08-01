/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void pred(Node* root,Node*& pre,int i){
        Node* curr = root;
        while(curr!=NULL){
           if(curr->key < i){
               pre = curr;
               curr = curr->right;
           }
           else{
               curr = curr->left;
           }
        }
    }
    void succ(Node* root,Node*& suc, int i){
        Node* curr = root;
        while(curr!=NULL){
            if(curr->key > i){
                suc = curr;
                curr = curr->left;
            }
            else{
                curr = curr->right;
            }
        }
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        suc = NULL;
        pre = NULL;
        succ(root,suc,key);
        pred(root,pre,key);
    }
};
