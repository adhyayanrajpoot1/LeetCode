class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        int n= s.size();
        int m = t.size();
        if(n!=m)return false;
        for(int i = 0; i < n ; i++)
        {
            m1[s[i]]++;
            m2[t[i]]++;
        }
        for(auto it : m1)
        {
            char ch = it.first;
            if(m2.find(ch)!=m2.end())
            {
                if(m2[ch]!=it.second)return false;
            }else return false;
        }
        return true;
    }
};