class Solution {
public:
    // TC-O(N)  ||  SC-O(N) for stack
    bool isValid(string s) {
        
        int n=s.size();
        
        stack<char> st;
        
        for(int i=0;i<n;i++)
            {
               char ch=s[i];
              
               if(ch=='(' || ch=='{' || ch=='[')
                   st.push(ch);
            else
             {
            if(st.empty())
                st.push(ch);
            
            if((st.top()=='(' && ch==')') || (st.top()=='{' && ch=='}') || (st.top()=='[' && ch==']'))
                st.pop();
                
            else 
                st.push(ch);
               }
            }
        
        return st.empty();
    }
};