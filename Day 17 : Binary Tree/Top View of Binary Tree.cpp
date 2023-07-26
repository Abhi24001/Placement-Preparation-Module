/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/
class Solution
{
    public:
    
    vector<int> topView(Node *root)
    {
        map<int,int> mpp;
        queue<pair<int,Node *>> q;
        q.push({0,root});
        while(!q.empty()){
            root=q.front().second;
            int x=q.front().first;
            q.pop();
            if(root->left){q.push({x-1,root->left});}
            if(root->right){q.push({x+1,root->right});}
            if(mpp.find(x)==mpp.end()){
                mpp[x]=root->data;
            }
        }
        vector<int> ans;
        for(it:mpp){
            ans.push_back(it.second);
        }
        return ans;
    }

};
