class Solution {
public:
    void f(vector<int>& nums,vector<vector<int>>&ans , vector<int>&smallAns,int begin)
    {
        ans.push_back(smallAns);
        
        for(int i = begin ; i < nums.size();i++)
        {
            if(i==begin || nums[i]!=nums[i-1])
            {
                smallAns.push_back(nums[i]);
                f(nums,ans,smallAns,i+1);
                smallAns.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>smallAns;
        sort(nums.begin(),nums.end());
        f(nums,ans,smallAns,0);
        return ans;
    }
};