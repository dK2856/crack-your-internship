class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int s=nums.size();
        int sum=0,sum1=0;
        for(int i=0;i<=s;i++)
        {
            sum+=i;
        }
        for(int i=0;i<s;i++)
        {
            sum1+=nums[i];
        }
        int d=sum-sum1;
        
        return d;
    }
};