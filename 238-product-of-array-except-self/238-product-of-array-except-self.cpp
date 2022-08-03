class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p1=1,p2=1;
        int n = nums.size();
        vector<int>ans(n,1);
        for(int i = 0 ; i < n ; i++)
        {
            ans[i]*=p1;
            p1=p1*nums[i];
            int j = n-i-1;
            ans[j]*=p2;
            p2=p2*nums[j];
        }
        return ans;
    }
};