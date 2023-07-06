class Solution {
  public:
    // TC-O(V+E)  ||  SC-O(2E)
    void dfs(int node,vector<int> adj[],vector<int> &vis,vector<int> &result)
    {
        vis[node]=1;
        
        result.push_back(node);
        
        for(auto it:adj[node])
        {
            if(vis[it]!=1)
              dfs(it,adj,vis,result);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        
        vector<int> result;
        
        dfs(0,adj,vis,result);
        
        return result;
    }
};