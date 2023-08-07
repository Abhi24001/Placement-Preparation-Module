

class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
       vector<int> al;
     queue<int> q;
      vector<bool> vis(V, false);

        q.push(0);  // adding the first node
        vis[0] = true;  // mark it visited.

        while (!q.empty()) {
            int curr = q.front();  // dequeueing and adding into al
            q.pop();
            al.push_back(curr);

            for (int neighbour : adj[curr])
                if (!vis[neighbour]) {
                    vis[neighbour] = true;
                    q.push(neighbour);
                }
        }
        return al;
    }
};
