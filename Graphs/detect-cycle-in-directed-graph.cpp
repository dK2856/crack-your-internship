Method 1:- Using Topological Sort(BFS Traversal)

class Solution {
  public:

    bool isCyclic(int V, vector<int> adj[]) {
        
	    vector<int> indegree(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        for(auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    
	    queue<int> q;  int count=0;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(indegree[i]==0) q.push(i);
	    }
	    
	    while(!q.empty())
	    {
	        int node=q.front(); q.pop();
	        
	        count++;
	        
	        for(auto it: adj[node])
	        {
	            indegree[it]--;
	            
	            if(indegree[it]==0) q.push(it);
	        }
	    }
	
	    if(count==V)return false;
	    else return true;
    }
};


Method 2:- Using DFS Traversal

class Solution {
  public:

    bool isCyclic(int V, vector<int> adj[]) {
        
        vector<int> vis(V,0);
        vector<int> path(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
               if(dfs(adj,vis,path,V,i)==true)
                 return true;
            }
        }
        
        return false;
    }
  private:
     bool dfs(vector<int> adj[],vector<int> &vis,vector<int> &path,int V,int node)
     {
         vis[node]=1;     path[node]=1;
         
         for(auto it : adj[node])
         {
             if(!vis[it])
             {
                 if(dfs(adj,vis,path,V,it)==true) return true;
             }
             else if(path[it]==1)
             {
                 return true;
             }
         }
         path[node]=0;
         
         return false;
     }
};

