class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[p.length()+1][s.length()+1];
        
        for(int i = 0 ; i < p.length()+1 ; i++)
        {
            for(int j = 0 ; j < s.length()+1 ; j++)
            {
                if(i==0&&j==0)
                {
                    dp[i][j] = true;
                }
                else if(i==0)
                {
                    dp[i][j]=false;
                }
                else if(j==0)
                {
                    if(p[i-1]=='*')
                    {
                        dp[i][j] = dp[i-2][j];
                    }
                    else dp[i][j]=false;
                }
                else{
                    if(p[i-1]=='*')
                    {
                        dp[i][j] = dp[i-2][j];
                        if(p[i-2]=='.' || p[i-2]==s[j-1])
                        {
                            dp[i][j] =dp[i][j]||dp[i][j-1];
                        }
                    }
                    else if(p[i-1]=='.')
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else if(p[i-1]==s[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else
                    {
                        dp[i][j] = false;
                    }
                }
            }
        }
        return dp[p.length()][s.length()];
    }
};