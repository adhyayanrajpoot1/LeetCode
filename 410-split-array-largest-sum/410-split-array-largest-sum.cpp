class Solution {
public:
    //int f(vector<int>&nums , )
    bool isPossible(vector<int>&nums , int m , int mid)
    {
        int sa = 1;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            sum+=nums[i];
            if(sum > mid)
            {
                sa++;
                sum = nums[i];
            }
        }
        return sa<=m;
    }
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int sum = 0;
        int maxi = nums[0];
        for(int i = 0 ; i < n ; i++)
        {
            sum+=nums[i];
            maxi = max(maxi , nums[i]);
        }
        int l = maxi;
        int h = sum;
        int ans= 0 ;
        while(l<=h)
        {
            int mid = l+(h-l)/2;
            if(isPossible(nums,m,mid)){
                ans = mid;
                h = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        return ans;
        
    }
};