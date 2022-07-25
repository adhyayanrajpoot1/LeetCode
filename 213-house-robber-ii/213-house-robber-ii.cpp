class Solution {
public:
    
    //int dp[10000];
     int f( int l, int r,vector<int>& nums) {
        int pre = 0, cur = 0;
        for (int i = l; i <= r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
    
    int rob(vector<int>& nums) {
        //memset(dp,0,sizeof(dp));
        int n = nums.size();
        if(n<2)return n?nums[0]:0;
        return max(f(0,n-2,nums),f(1,n-1,nums));
    }
};