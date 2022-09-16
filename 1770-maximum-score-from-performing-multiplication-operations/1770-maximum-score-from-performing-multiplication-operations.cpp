class Solution {
public:
    int dp[1001][1001];
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        memset(dp,0,sizeof(dp));
        for(int i=multi.size()-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                long long left=nums[j]*multi[i]+dp[i+1][j+1];
        long long right=((long long)nums[nums.size()-1-(i-j)]*multi[i])+dp[i+1][j];
           dp[i][j]=max(left,right);
            }
        }
        // for(int i = 0 ;  i <10 ; i++)
        // {
        //     for(int j = 0; j < 10 ; j++)
        //     {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[0][0];
    }
    
};










// int dp[1001][1001] = {};
// int dfs(vector<int>& nums, vector<int>& mults, int l, int i) {
//     if (i >= mults.size())
//         return 0;
//     if (!dp[l][i]) {
//         int r = nums.size() - 1 - (i - l);
//         dp[l][i] = max(nums[l] * mults[i] + dfs(nums, mults, l + 1, i + 1), 
//             nums[r] * mults[i] + dfs(nums, mults, l, i + 1));
//     }
//     return dp[l][i];
// }
// int maximumScore(vector<int>& nums, vector<int>& mults) {
//     return dfs(nums, mults, 0, 0);
// }