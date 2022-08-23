class Solution {
public:
    void f(string &s)
    {
        stack<int>st;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i]=='#')
            {
                if(st.size()!=0)
                {
                    st.pop();
                }
            }
            else{
                st.push(s[i]);
            }
        }
        s="";
        while(!st.empty())
        {
            char ele = st.top();
            st.pop();
            s = ele+s;
        }
        
    }
    bool backspaceCompare(string s, string t) {
        f(s);
        f(t);
        return s==t;
    }
};