class Solution {
public:
    bool isValid(string s) {
        
        int n=s.size();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
               st.push(s[i]);
            else 
            {
                if(!st.empty())
                {
                    if(s[i]==')' && st.top()=='(' || s[i]=='}' && st.top()=='{' || s[i]==']' &&  st.top()=='[')
                       st.pop();
                    else    // other than closing sequence so it is false
                       return false;
                }
                else    // no closing sequence so it is false
                   return false;
            }
        }
        if(st.empty()) // all opening corresponds its closing so it is true
           return true;

        return false;
    }
};