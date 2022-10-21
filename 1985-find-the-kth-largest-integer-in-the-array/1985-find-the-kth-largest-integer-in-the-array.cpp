class Solution {
public:
    static bool cmp(string&a , string &b)
    {
        if(a.length()>b.length())return true;
        else if(a.length()==b.length())
        {
            return a>b;
        }
        return false;
    }
    string kthLargestNumber(vector<string>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);
        for(auto it : nums)cout<<it<<" ";
        return nums[k-1];
    }
};