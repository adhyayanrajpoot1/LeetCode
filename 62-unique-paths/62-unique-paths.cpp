class Solution {
public:
    int ans = 0;
    int dp[101][101];
    int f(int m , int n)
    {
        if(m==1 && n==1)return 1;
        if(dp[m][n]!=-1)return dp[m][n];
        int small = 0;
        if(m>1)
        small +=f(m-1,n);
        if(n>1)small+=f(m,n-1);
        return dp[m][n] = small;
        
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof dp);
    
        return f(m,n);
        
       
        
        
        
    }
};