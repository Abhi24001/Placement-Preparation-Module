class BSTIterator {
public:
    stack<TreeNode*> st;  
    void pushAll(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushAll(root);  
    }
    int next() {
        auto temp = st.top(); 
        st.pop();  
        pushAll(temp->right);  
        return temp->val; 
    }
    bool hasNext() {
        return !st.empty();  
    }
};
