class Solution {
public:
    int f(int i , int j , string&s ,vector<vector<int>>&dp)
    {
        if(i==j)return 1;
        if(i>j)return 0;
        int &ans = dp[i][j];
        if(ans!=-1)return ans;
        if(s[i]==s[j])return ans = 2+f(i+1,j-1,s,dp);
        else return ans = max(f(i+1,j,s,dp),f(i,j-1,s,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>>v(n,vector<int>(n,-1));
        return f(0,n-1,s,v);
    }
};