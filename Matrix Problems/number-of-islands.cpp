class Solution {
public:
    // TC-O(N^2)  ||  SC-O(N^2)
    // DFS can also be done
    void bfs(vector<vector<char>> &grid,vector<vector<int>> &vis,int row,int col)
    {
        int n=grid.size(),m=grid[0].size();
        
        queue<pair<int,int>> q;
        
        vector<pair<int,int>> directions={{-1,0},{0,1},{1,0},{0,-1}}; //It determines all the 4 directions of motion
        
        q.push({row,col});
        vis[row][col]=1;
        
        while(!q.empty())
        {
           int row=q.front().first;
           int col=q.front().second;
            q.pop();
            
            // Traversing the neighbours of the node in all 4 directions(consider all boundary conditions)
            for(int i=0;i<directions.size();i++)
            {
                int nrow=row+(directions[i].first);  int ncol=col+(directions[i].second);
                    
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1')
                 {
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                 }
             }
         }
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size(),m=grid[0].size(),count=0;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    bfs(grid,vis,i,j);
                }
            }
        }
        return count;
    }
};