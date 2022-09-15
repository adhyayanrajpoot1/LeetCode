class Solution {
public:
    bool f(string&s , string&p , int i , int j , vector<vector<int>>&dp)
    {
        if(i==s.size() && j == p.size())return true;
        if(j>=p.size())return false;
        if(dp[i][j]!=-1)return dp[i][j];
        bool ans = false;
        if(i<s.size() && s[i]==p[j])
        {
            ans|=f(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='?')
        {
            if(i==s.size())return false;
            else
                ans|=f(s,p,i+1,j+1,dp);
        }
        else if(p[j]=='*')
        {
            if(i<s.size())
            {
                ans|=f(s,p,i+1,j,dp);
            }
            ans|=f(s,p,i,j+1,dp);
            
        }
        return dp[i][j] = ans;
    }
    bool isMatch(string s, string p) {
        vector<vector<int>>dp(s.size()+1,vector<int>(p.size()+1,-1));
        return f(s,p,0,0,dp);
    }
};