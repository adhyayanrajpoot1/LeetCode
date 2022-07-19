class Solution {
public:
    void f(vector<int>& nums , vector<vector<int>>&ans , int pos)
    {
        if(pos==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int>s;
        for(int i = pos ; i < nums.size() ; i++)
        {
            if(s.find(nums[i])==s.end())
            {
                s.insert(nums[i]);
                swap(nums[i],nums[pos]);
                f(nums,ans,pos+1);
                swap(nums[i],nums[pos]);
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        f(nums,ans,0);
        return ans;
        
    }
};