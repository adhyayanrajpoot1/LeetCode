class Solution {
public:
    int numTrees(int n) {
        int*dp = new int[n+1]();
        dp[0] = 1;
        dp[1] = 1;
        if(n==0 || n==1)return n;
        //dp[2] = 2;
        //dp[3] = 5;
        
        for(int i = 2 ; i <= n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};