class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int ind1=-1;
        int n =nums.size();
        if(n==1)return;
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                ind1=i;
                break;
            }
        }
        if(ind1==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        int ind2=-1;
        for(int i = n-1;i>=0;i--)
        {
            if(nums[i]>nums[ind1])
            {
                ind2=i;
                break;
            }
        }
        swap(nums[ind1],nums[ind2]);
        reverse(nums.begin()+ind1+1,nums.end());
    }
};