class Solution {
public:
    // TC-O(M*N*(4^L)) ||  SC-O(N)
    bool dfs(vector<vector<char>> &board,vector<vector<int>> &vis,string word,int row,int col,int i,int count)
    {
        int n=board.size(),m=board[0].size();
        
        vis[row][col]=1;
        
        if(count==word.size()) return true;
        
        for(int j=0;j<4;j++)
        {
            int nrow=row+directions[j].first;
            int ncol=col+directions[j].second;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && word[i]==board[nrow][ncol])
            {
               if(dfs(board,vis,word,nrow,ncol,i+1,count+1))
               {
                    return true;
               }
            }
        }
        
        vis[row][col]=0;     return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
     
        int n=board.size(),m=board[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(board,vis,word,i,j,1,1)) return true;
                }
            }
        }
        
        return false;
    }
    
private:
    
    vector<pair<int,int>> directions={{-1,0},{0,1},{1,0},{0,-1}};
    
};