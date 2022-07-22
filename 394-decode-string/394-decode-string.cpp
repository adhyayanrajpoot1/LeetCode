class Solution {
public:
        string decodeString(string s)
    {
        int n=s.length();
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]!=']')
                st.push(s[i]);
            else
            {
                string ss="";
                while(!st.empty() && st.top()!='[')
                {
                    ss=st.top()+ss;
                    st.pop();
                }
            
                st.pop();
            
                string number="";
                while(!st.empty() && isdigit(st.top()))
                {
                   number=st.top()+number;
                   st.pop();
                }
            
                int k=stoi(number);
            
                while(k--)
                {
                   for(int j=0;j<ss.length();j++)
                       st.push(ss[j]);
                }
           }
        }
        
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};


/*
Logic

First make a char stack.
Traverse the string.
If the char is not a ] 
    push it into the stack.
Else 
    store all elements of the stack in a string in reverse fashion until we encounter a [.
    pop the top element of stack as it it [.
    After that create a number string and store the frequency in reverse fashion. We use while here and not if because we can also have 2 digit or 3 digit number as frequency. Keep popping from stack.
    Then convert that number string into int k.
    now use a while loop until k>0 and store each char of string k number of times.
    
Now traverse through the stack and store all the characters in reverse order until stack becomes empty.
Finally, return ans.

*/
