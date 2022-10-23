class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>s;
        vector<int>ans;
        int sum = 0;
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                ans.push_back(nums[i]);
                //break;
            }
            s.insert(nums[i]);
            sum+=nums[i];
        }
        int n = nums.size();
        ans.push_back(n*(n+1)/2-sum+ans[0]);
        return ans;
        
    }
};