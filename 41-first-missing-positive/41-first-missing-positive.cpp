class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool isOne = false;
        int n  = nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]==1)isOne = true;
            if(nums[i] <1 || nums[i]>n)
            { 
                nums[i] = 1;
            }
            
        }
        if(isOne==false)return 1;
        for(auto it : nums)
        {
            it=abs(it);
            nums[it-1] = -abs(nums[it-1]);
        }
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]<0)continue;
            else{
                return i+1;
            }
        }
        return n+1;
        
    }
};