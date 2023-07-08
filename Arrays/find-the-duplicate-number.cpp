class Solution {
public:
    // TC-O(N) in one pass  ||   SC-O(1)
    // Concept- Loop in Linked List
    int findDuplicate(vector<int>& nums) {
        
        int slow=nums[0],fast=nums[0];
        
        do{
          slow=nums[slow];
          fast=nums[nums[fast]];
        } while(slow!=fast);
        
        fast=nums[0];
        
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};