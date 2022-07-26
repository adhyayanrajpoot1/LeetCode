class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int count=0;
        int total=0;
        int n = nums.size();
        for(int i = 2 ; i < n ; i++)
        {
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
            {
                count++;
                total+=count;
            }
            else{
                count=0;
            }
        }
        return total;
    }
};