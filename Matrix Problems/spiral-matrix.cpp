class Solution {
public:
    // TC-O(N*M)  ||  SC-O(1)
    // This has just one solution
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n=matrix.size(),m=matrix[0].size();
        
        vector<int> result;
        
        int left=0,right=m-1,top=0,bottom=n-1;
        
    while(top<=bottom && left<=right)    // Central element is reached
     {
            for(int i=left;i<=right;i++)      //  Right movement
            {
                result.push_back(matrix[top][i]);
            }
            
            top++; 
            
            for(int i=top;i<=bottom;i++)       //  Down movement
            {
                result.push_back(matrix[i][right]);
            }

            right--;
            
         if(top<=bottom)
         {
            for(int i=right;i>=left;i--)        //  Left movement
            {
                result.push_back(matrix[bottom][i]);
            }
           
            bottom--;
         }
          
         if(left<=right)
         {  
            for(int i=bottom;i>=top;i--)         // Up movement
            {
                result.push_back(matrix[i][left]);
            }
            
            left++;
             
         } 
       }
        
        return result;
    }
};