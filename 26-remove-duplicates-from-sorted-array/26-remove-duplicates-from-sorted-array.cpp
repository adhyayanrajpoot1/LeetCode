class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //if(nums.size()==1)return 1;
        int i = 1 ;
        int j = 1;
        int c =0;
        while(j<nums.size())
        {
            if(nums[j]!=nums[j-1]){
                nums[i] = nums[j];
                i++;
                c++;
            }
            j++;
        }
        //nums[i]=nums[j];
        return c+1;
    }
};