class Solution {
public:
    vector<vector<int>>f(vector<int>& nums , int i)
    {
        
        if(i==nums.size())return {{}};
        
        
        vector<vector<int>>smallAns = f(nums,i+1);
        vector<vector<int>>step;
        //not include
        for(auto it : smallAns)
        {
            step.push_back(it);
        }
        //include
        for(auto it : smallAns)
        {
            it.push_back(nums[i]);
            step.push_back(it);
        }
        return step;
        
        
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        return f(nums,0);
    }
};