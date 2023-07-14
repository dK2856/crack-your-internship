class Solution {
public:
    // TC-O(N*klogk)   ||   SC-O(N)for map
 vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
      vector<vector<string>> result;
        
        int n=strs.size();
        
        map<string,vector<string>> mp;
        
        for(int i=0;i<n;i++)
        {
            string s=strs[i];
            sort(s.begin(),s.end());
            
            mp[s].push_back(strs[i]);
        }
        
        for(auto it : mp)
        {
            result.push_back(it.second);
        }
        return result;
    }
};