class Solution {
public:
    int minMoves(vector<int>& nums) {
        //sum+m(n-1) = n*x
        int mini = INT_MAX;
        int sum = 0;
        for(auto it : nums)
        {
            sum+=it;
            mini = min(mini,it);
        }
        return sum-mini*nums.size();
    }
};