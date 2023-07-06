class Solution {
public:
    
    //Optimized solution using Hash Table 
    // TC- O(N)  and SC- O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        
        vector<int> result;

        unordered_map<int,int> map;

        int n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(map.find(target-nums[i])!=map.end())
            {
                result.push_back(map[target-nums[i]]);
                result.push_back(i);
                return result; 
            }
            map[nums[i]]=i;
        }
        return result;
    }
};