class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump = nums[0];
        for(int i = 0 ; i < nums.size(); i++)
        {
            maxJump = max(maxJump,i+nums[i]);
            if(maxJump<=i && i<nums.size()-1)return false;
        }
        return true;
        
    }
};