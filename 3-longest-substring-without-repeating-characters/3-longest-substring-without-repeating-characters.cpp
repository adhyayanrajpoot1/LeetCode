class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<int,int>mapp;
        int l = 0;
        int r = 0;
        int len=0;
        for(int i = 0 ; i < s.length() ;i++)
        {
            if(mapp.find(s[i])!=mapp.end()){
                l=max(mapp[s[i]]+1,l);
            }
            mapp[s[i]]=i;
            len=max(len,i-l+1);
            
        }
        return len;
    }
};