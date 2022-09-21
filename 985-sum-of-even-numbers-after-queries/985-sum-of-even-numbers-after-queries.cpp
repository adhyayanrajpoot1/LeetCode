class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum = accumulate(nums.begin(),nums.end(),0,[](int s , int a){ return s+((a%2==0)?a:0);});
        vector<int>res;
        for(auto it : queries)
        {
            if(nums[it[1]]%2==0)
            {
                sum-=nums[it[1]];
            }
            nums[it[1]]+=it[0];
            if(nums[it[1]]%2==0)sum+=nums[it[1]];
            res.push_back(sum);
        }
        return res;
    }
};