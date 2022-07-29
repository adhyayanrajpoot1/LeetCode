class Solution {
public:
    void sortColors(vector<int>& nums) {
        //three pointer
        int l = 0;
        int mid = 0;
        int r = nums.size()-1;
        while(mid<=r)
        {
            switch(nums[mid])
            {
                case 0:{
                    swap(nums[l],nums[mid]);
                    l++;
                    mid++;
                    break;
                }
                case 1: {
                    mid++;
                    break;
                }
                default : {
                    swap(nums[mid],nums[r]);
                    r--;
                }
            }
        }
    }
};