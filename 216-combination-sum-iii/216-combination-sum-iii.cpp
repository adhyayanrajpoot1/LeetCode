class Solution {
public:
    vector<vector<int>>ans;
    void f(int ind , int sum , int tar , int k ,vector<int>&ds,vector<int>&nums)
    {
        if(tar<sum)return;
        if(tar==sum)
        {
            if(k==0)
                ans.push_back(ds);
            return;
        }
        if(ind==nums.size())return;
        
        ds.push_back(nums[ind]);
        sum+=nums[ind];
        f(ind+1 , sum,tar,k-1,ds,nums);
        ds.pop_back();
        sum-=nums[ind];
        f(ind+1,sum,tar,k,ds,nums);
            
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums(9);
        iota(nums.begin() , nums.end(),1);
        vector<int>temp;
        f(0,0,n,k,temp,nums);
        return ans;
    }
};