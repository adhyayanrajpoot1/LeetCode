class Solution {
public:
    int kadanes(vector<int>&nums)
    {
        int curr=0;
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size();i++)
        {
            curr+=nums[i];
            maxi = max(maxi , curr);
            if(curr<0)curr = 0;
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int>newA(n);
        int sum = 0;
        int neg = INT_MIN;
        for(int i = 0 ;  i< n ; i++)
        {   
            neg = max(neg,nums[i]);
            newA[i] = -1*nums[i];
            sum+=newA[i];
        }
        if(neg<0)return neg;
        int ans = kadanes(newA);
        int high = kadanes(nums);
        cout<<ans;
        int small = -(sum)-(-ans);
        return max(high,small);
        
        
        
        
    }
};