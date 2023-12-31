class Solution {
public:
    //TC-O(NlogN)   ||   SC-O(1)
    int maximumProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        int val1=nums[n-1]*nums[n-2]*nums[n-3];
        
        int val2=nums[0]*nums[1]*nums[n-1];
        
        return max(val1,val2);
    }
};