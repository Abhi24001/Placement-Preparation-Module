class Solution {
  public:
    vector<int> ans;    

   // Function to return a list containing the DFS traversal of the graph.   
    void dfs(int node,vector<int> adj[],vector<bool> &vis){
        vis[node]=true;
        ans.push_back(node);
        for(auto &child:adj[node]){
            if(!vis[child]) dfs(child,adj,vis);
        }
        return;
    }
    
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // visited array
        vector<bool> vis(V,false);
        
       // dfs call
        dfs(0,adj,vis);
        
        return ans;
    }
};
