class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxP = 1;
        int minP = 1;
        int best = INT_MIN;
        
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]<0){
                swap(maxP , minP);
            }
            maxP = max(maxP*nums[i],nums[i]);
            minP = min(minP*nums[i],nums[i]);
            best = max(best,maxP);
        }
        return best;
        
        
    }
};