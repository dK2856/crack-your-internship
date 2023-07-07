class Solution {
public:
    //TC-O(N^2)  ||  SC-O(3N)
    //Using Cycle Detection technique by DFS Traversal
    
    bool dfs(vector<vector<int>> &graph,vector<int> &vis,vector<int> &pathVis,vector<int> &isSafe,int node)
    {
        vis[node]=1;  pathVis[node]=1;
        
        isSafe[node]=0;
        
        for(auto it : graph[node])
        {
            if(!vis[it])
            {
                if(dfs(graph,vis,pathVis,isSafe,it))
                {
                   isSafe[it]=0; return true;
                }
            }
            else if(pathVis[it])
            {
                isSafe[it]=0;  return true;
            }
        }
        
        isSafe[node]=1;
        
        pathVis[node]=0;
        
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n=graph.size();
        
        vector<int> pathVis(n,0);  vector<int> vis(n,0);
        
        vector<int> isSafe(n,0);
        
        vector<int> result;
        
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
              dfs(graph,vis,pathVis,isSafe,i);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(isSafe[i])
            {
                result.push_back(i);
            }
        }
        
        return result;
    }
};