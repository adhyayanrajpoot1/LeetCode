class Solution {
public:
    bool isSubsequence(string s, string t) {
        // unordered_map<char,int>mapp;
        // for(int i = 0 ; i < n ; i++)
        // {
        //     mapp[t[i]] = i;
        // }
        int j = 0;
        if(s.size()==0)return true;
        if(t.size()==0 && s.size()!=0)return false;
        for(int i = 0; i < t.length() ; i++)
        {
            if(t[i]==s[j])
            {
                j++;
                if(j==s.length())return true;
            }
        }
        return false;
    }
};