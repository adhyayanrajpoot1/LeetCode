class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(st.empty())st.push(s[i]);
            else if(st.top()!=s[i])
            {
                st.push(s[i]);
            }
            else
            {
                st.pop();
            }
            
        }
        string ans;
        while(!st.empty())
        {
            ans = st.top()+ans;
            st.pop();
        }
        
        return ans;
    }
};