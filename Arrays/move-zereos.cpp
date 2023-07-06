class Solution {
public:
    // TC-O(2N)  ||  SC-O(N) for queue
    void moveZeroes(vector<int>& nums) {
        
       int n=nums.size(),i=0;
        queue<int> q;
        
        for(int k=0;k<n;k++)
        {
            if(nums[k]!=0) q.push(nums[k]);
        }
        
        while(!q.empty())
        {
            nums[i]=q.front();
            q.pop();
            i++;
        }
        
        for(int j=i;j<n;j++)
          nums[j]=0;
    }
};