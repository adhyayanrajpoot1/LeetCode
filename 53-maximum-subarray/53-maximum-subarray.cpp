class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currMax = nums[0];
        int maxSoFar = nums[0];
        for(int i = 1 ; i < nums.size();i++)
        {
            currMax= max(currMax+nums[i],nums[i]);
            
            maxSoFar = max(maxSoFar,currMax);
        }
        return maxSoFar;
    }
};