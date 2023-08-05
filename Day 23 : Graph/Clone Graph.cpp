
class Solution {
public:
map<Node* , Node*>mp;
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        if(mp.find(node)!=mp.end())return mp[node];
        Node* temp= new Node(node->val);
        vector<Node*>v;
        mp[node]=temp;
       for(auto x:node->neighbors){
         v.push_back(cloneGraph(x)); 
       }
       temp->neighbors=v;
        return temp;
    }
};
