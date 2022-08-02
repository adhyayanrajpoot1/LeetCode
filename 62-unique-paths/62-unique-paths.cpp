class Solution {
public:
//     int ans = 0;
//     int dp[101][101];
//     int f(int m , int n)
//     {
//         if(m==1 && n==1)return 1;
//         if(dp[m][n]!=-1)return dp[m][n];
//         int small = 0;
//         if(m>1)
//         small +=f(m-1,n);
//         if(n>1)small+=f(m,n-1);
//         return dp[m][n] = small;
        
//     }
    int uniquePaths(int m, int n) {
        //memset(dp,1,sizeof dp);
    
        //return f(m,n);

        vector<vector<long long>>dp(m+1,vector<long long>(n+1,1));
        for(int i = 1 ; i <= m ; i++)
        {
            for(int j = 1 ; j <=n  ; j++)
            {
            
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
                cout<<dp[i][j]<<" ";
                 
            }
        }
        return dp[m-1][n-1];
        
    }
};


// class Solution {
//     public int uniquePaths(int m, int n) {
//         int grid[][] = new int[m][n];
//         int[][]dp = new int[m+1][n+1];
//         for(int x=m;x>=0;x--){
//             for(int y=n;y>=0;y--){
//                 if(x == m || y == n) dp[x][y] = 0;
//                 else if(x == m-1 && y == n-1) dp[x][y] = 1;
//                 else dp[x][y] =  dp[x+1][y] + dp[x][y+1]; 
//             }
//         }
//         return dp[0][0];
//     }
// }