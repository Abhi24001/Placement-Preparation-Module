//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int>ans;
        map<int,int>mp;
        //pair type queue to store Node and its hd
        queue<pair<Node*,int>>q;
        if(root==NULL)
        return ans;
        q.push(make_pair(root,0));
        while(!q.empty())
        {
            pair<Node*,int> temp=q.front();
            q.pop();
            
            Node* frontNode= temp.first;
            int hd=temp.second;
            //entry created and will be updated till the last value for that hd
            //giving us the values of bottom view
            mp[hd]=frontNode->data;
            if(frontNode->left)
            {
                //-1 for left of node
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right)
            {
                //+1 for right of node
                q.push(make_pair(frontNode->right,hd+1));
            }
            
        }
        for(auto i:mp)
        {
            //storing the values in a vector
            ans.push_back(i.second);
        }
    return ans;
    }
};
