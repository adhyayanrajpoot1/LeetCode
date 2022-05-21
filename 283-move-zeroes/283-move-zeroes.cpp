class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int k = nums.size()-1;
        if(k+1==1)return;
        for(int i = nums.size()-2;i>=0;i--)
        {
            if(nums[i]==0)
            {
                int x;
                for( x = i ; x < k;x++)
                {
                    nums[x]=nums[x+1];
                }
                if(nums[k]!=0)
                nums[k--]=0;
                
            }
        }
    }
};