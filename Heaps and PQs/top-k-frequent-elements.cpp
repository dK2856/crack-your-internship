class Solution {
public:
    // TC-O(NlogN)-2pass  ||  SC-O(2N)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        int n=nums.size();
        
        vector<int> result;
        
        unordered_map<int,int> map;
        
        for(int i=0;i<n;i++)
        {
            map[nums[i]]++;
        }
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it:map)
        {
            pq.push({it.second,it.first});
        }
        
        while(k && !pq.empty())
        {
            auto x=pq.top();
            pq.pop();
            int val=x.second;
            result.push_back(val);
            k--;
        }
        return result;
    }
};