class Solution {
public:
   //Basically,it is a problem of Counting Sort.  
    
    void sortColors(vector<int>& nums){
        
        int n=nums.size();
        int c1=0,c2=0;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                c1++;
            
            if(nums[i]==1)
                c2++;
        }
        for(int i=0;i<c1;i++)
        {
            nums[i]=0;
        }
        for(int i=c1;i<(c1+c2);i++)
        {
            nums[i]=1;
        }
        for(int i=(c1+c2);i<n;i++)
        {
            nums[i]=2;
        }
    }
};