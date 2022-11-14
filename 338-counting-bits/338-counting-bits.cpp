class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1);
        for(int i = 0 ; i <= n ; i++)
        {
            int count =0;
            int j = i;
            while(j!=0)
            {
                if(j&1)count++;
                j=j/2;
            }
            dp[i] = count;
        }
        return dp;
        
    }
};