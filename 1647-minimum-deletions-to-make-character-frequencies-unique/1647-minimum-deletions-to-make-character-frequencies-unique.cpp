class Solution {
public:
    int minDeletions(string s) {
        vector<int>arr(26);
        for(int i = 0 ; i < s.length() ; i++)
        {
            arr[s[i]-'a']++;
        }
        sort(arr.begin() , arr.end() , greater<int>());
        int ans = 0;
        int f = arr[0];
        
        for(auto it : arr)
        {
            if(f<it)
            {
                if(f>0)
                {
                    ans+=(it-f);
                }
                else
                {
                    ans+=it;
                }
            }
            f=min(f-1,it-1);
        }
        return ans;
    }
};