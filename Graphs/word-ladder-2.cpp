class Solution {
public:
// TC-O(N^2+M)  ||  SC-O(N+M)
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
       
       int n=wordList.size();
       
       vector<vector<string>> result;
       
       unordered_set<string> s(wordList.begin(),wordList.end());
       
       queue<vector<string>> q;  q.push({beginWord});
       
       int level=0;  vector<string> usedOnLevel;
       
       usedOnLevel.push_back(beginWord);
       
       while(!q.empty())
       {
           vector<string> v=q.front(); q.pop();
           
           if(v.size()>level)
           {
               level++;
               
               for(auto it : usedOnLevel)
               {
                   s.erase(it);
               }
           }
           
           string str=v[v.size()-1];
           
           if(str==endWord)
           {
               if(result.size()==0)
               {
                   result.push_back(v);
               }
               else if(result[0].size()==v.size())
               {
                   result.push_back(v);
               }
           }
           
           for(int i=0;i<str.size();i++)
           {
               char initial=str[i];
               
               for(char ch='a';ch<='z';ch++)
               {
                   str[i]=ch;
                   
                   if(s.find(str)!=s.end())
                   {
                       v.push_back(str);
                       
                       q.push(v);
                       
                       usedOnLevel.push_back(str);
                       
                       v.pop_back();
                   }
               }
               
               str[i]=initial;
           }
       }
       
       return result;
    }
};
