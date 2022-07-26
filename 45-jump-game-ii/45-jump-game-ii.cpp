class Solution {
public:
    vector<int>ans;
    int f(int ind , vector<int>& nums)
    {
        if(ind>=nums.size()-1)return 0;
        //if(ind==nums.size()-1)return 1;
        //int reachable = ind+nums[ind];
        if(ans[ind]!=-1)return ans[ind];
        int a = 1e9;
        for(int i = 1 ; i <=nums[ind] ; i++)
        {
            //dp[i] = min(dp[i],1+dp[ind]);
            int small = 1+f(i+ind,nums);
            a=min(a,small);
        }
        //int ans = f(ind+nums[ind],nums);
        //if(ans==0)return 0;
        return ans[ind] = a;
    }
    int jump(vector<int>& nums) {
        
            int n = nums.size();
            ans.resize(n+1,-1);
//         vector<int>dp(n+1,1e7);
        
//         dp[0]=0;
//         for(int i = 1 ; i < n ; i++)
//         {
//             int k = i-1;
//             for(int j = nums[i]; k>=0  && j>0; j--)
//             {
//                 dp[i]=min(dp[i], 1+dp[k--]);
//             }
//         }        
        return f(0,nums);
    }
};