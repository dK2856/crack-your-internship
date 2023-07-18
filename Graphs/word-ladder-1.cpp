class Solution {
public:
  // TC-O(N^2+M)  ||  SC-O(N+M)
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        
        int n=wordList.size();
        
        unordered_set<string> s(wordList.begin(),wordList.end());
        
        queue<pair<string,int>> q;
        
        q.push({startWord,1});
        
        s.erase(startWord);
        
        while(!q.empty())
        {
            auto x=q.front();  q.pop();
            
            string str=x.first;
            int level=x.second;
            
            if(str==targetWord) return level;
            
            for(int i=0;i<str.size();i++)
            {
                char initial=str[i];
                
                for(char ch='a';ch<='z';ch++)
                {
                    str[i]=ch;
                    
                    if(s.find(str)!=s.end())
                    {
                        q.push({str,level+1}); s.erase(str);
                    }
                }
                
                str[i]=initial;
            }
            
        }
        
        return 0;
    }
};
