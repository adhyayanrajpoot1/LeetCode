class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int peak = 1 , valley =1;
        int n = nums.size();
        for(int i = 1 ; i < n ; i++)
        {
            if(nums[i]>nums[i-1])peak = valley+1;
            else if(nums[i]<nums[i-1])valley = peak+1;
        }
        return max(peak , valley);
    }
};