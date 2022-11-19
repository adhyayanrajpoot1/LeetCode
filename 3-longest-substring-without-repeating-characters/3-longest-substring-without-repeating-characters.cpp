class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>arr(256,-1);
        
        int l = 0;
        int r = 0;
        int len = 0;
        int n = s.size();
        while(r<n)
        {
            if(arr[s[r]]!=-1)l = max(l,arr[s[r]]+1);
            arr[s[r]] = r;
            len = max(len , r-l+1);
            r++;
            
            
        }
        return len;
    }
};