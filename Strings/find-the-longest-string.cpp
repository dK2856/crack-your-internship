
// Question Link : https://practice.geeksforgeeks.org/problems/8d157f11af5416087251513cfc38ffc4d23be308/1

class Solution
{
public:
    static bool cmp(string a,string b)
    {
        if(a.size()!=b.size()) return a.size()>b.size();
        
        return a<b;
    }
    
    string longestString(vector<string> &words)
    {
        sort(words.begin(),words.end(),cmp);
        
        string ans="";
        
        unordered_map<string,int> mp;
        
        for(int i=0;i<words.size();i++)
        {
            mp[words[i]]++;
        }
        
        for(int i=0;i<words.size();i++)
        {
            string t=""; int flag=1;
            
            for(int j=0;j<words[i].size();j++)
            {
                t+=words[i][j]; ans=t;
                
                if(mp.find(t)==mp.end())
                {
                    flag=0; break;
                }
            }
            
            if(flag==1) return ans;
        }
        
        return "";
    }
};