class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1,s2;
        int i = 0, j = 0;
        while(i < s.length() or j < t.length())
        {
            if(i<s.length())
            {
                if(!s1.empty() &&s[i]=='#')
                {
                    s1.pop();
                }
                else if(s[i]!='#')s1.push(s[i]);
                i++;
            }
            if(j<t.length())
            {
                if(!s2.empty() &&t[j]=='#')
                {
                    s2.pop();
                }
                else if(t[j]!='#')s2.push(t[j]);
                j++;
            }
        }
        string str1,str2;
        while(s1.size()!=0)
        {
            str1 = s1.top()+str1;
            s1.pop();
        }
        while(s2.size()!=0)
        {
            str2 = s2.top()+str2;
            s2.pop();
        }
        cout << str1 << " "<<str2;
        return str1==str2;
    }
};