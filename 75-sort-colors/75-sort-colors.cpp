class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0 , r = nums.size()-1 , mid = 0;
        
        for(int i = 0 ; i < nums.size() ; i++)
        {
            switch(nums[mid]){
                case 0:
                    {
                        swap(nums[mid],nums[l]);
                        l++;
                        mid++;
                        break;
                    }
                case 1:
                    {
                        mid++;
                        break;
                    }
                case 2:
                    {
                        swap(nums[mid],nums[r]);
                        r--;
                        //break;
                    }
            }
        }
    }
};