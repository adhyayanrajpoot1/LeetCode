class Solution {
public:
    int memo[101];
    int f(int ind , vector<int>& nums)
    {
        if(ind==0)return nums[ind];
        if(ind==1)return max(nums[ind-1],nums[ind]);
        int &ans = memo[ind];
        if(ans!=-1)return ans;
        
        return ans = max(f(ind-2,nums)+nums[ind],f(ind-1,nums));
    }
    int rob(vector<int>& nums) {
        //if(nums.size()==1 || nums.size()==2)return nums[nums.size()-1];
        memset(memo,-1,sizeof(memo));
        return f(nums.size()-1,nums);
    }
};