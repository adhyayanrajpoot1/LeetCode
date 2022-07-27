class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mapp;
        int n=nums.size();
        for(int i = 0 ; i < n ; i++)
        {
            if(mapp.find(target-nums[i])!=mapp.end())
            {
                ans.push_back(mapp[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }mapp[nums[i]]=i;
        }return ans;
    }
};