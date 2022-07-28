class Solution {
public:
    int longestPalindrome(string s) {
        long long ans = 0;
        int v = 0;
        int arr[126]={0};
        for(int i = 0 ;i <s.length();i++)
        {
            arr[s[i]]++;
        }
        
        for (auto it : arr)
        {
            if(it!=0)
            cout<<it/2*2;
            ans+=it/2*2;
            if(ans%2==0 && it%2==1)
            {
                ans++;
            }
        }
        return ans;
    }
};