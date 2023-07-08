class Solution {
public:
    // TC-O(N^2)   ||   SC-O(1)
    vector<vector<int>> threeSum(vector<int>& nums) {
            
       int n=nums.size();
        
        vector<vector<int>>result;
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n-2;i++)
        {
            if(i==0 || (i>0 && nums[i-1]!=nums[i]))
            {
                int sum=-nums[i];
                int j=i+1,k=n-1;
                
                while(j<k)
                {
                    if(nums[j]+nums[k]==sum)
                    {
                        vector<int> v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[k]);
                        result.push_back(v);
                        
                        while(j<k && nums[j]==nums[j+1])
                            j++;
                        
                        while(j<k && nums[k]==nums[k-1])
                            k--;
                        
                        j++; k--;
                    }
                    else if(nums[j]+nums[k]>sum)
                        k--;
                    else
                        j++;
                }
            }
        }
        return result;
    }
};

/* To ignore repetition of values, we write a condition in lines 29 and 32.
   While loop will run until it finds the similar numbers before(for k) 
   and after(for j). Also the condition in line 14 is done to avoid any 
   repetitive values of i                                                */