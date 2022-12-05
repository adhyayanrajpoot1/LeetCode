class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        //vector<long long>pre(n,0);
        //pre[0] = nums[0];
        long long sum = 0;
        for(int i = 0 ; i < n ; i++)
        {
            sum+=nums[i];
            //pre[i] = pre[i-1]+nums[i];
        }
        long long ans = INT_MAX;
        int index = -1;
        long long sumI = 0;
        long long lsum = 0;
        long long rsum = sum;
        for(int i = 0 ; i < n ; i++)
        {
            sumI += nums[i];
            lsum +=nums[i];
            rsum -=nums[i];
            int a = (lsum/(i+1));
            int b = (i==(n-1)) ? 0 : rsum/((n-i-1));
            int small = abs( a-b );
            if(small < ans)
            {
                index = i;
                ans = small;
            }
        }
        return index;
    }
};