class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        long long shortest = INT_MAX;
        deque<pair<long long,long long>>dq;
        for(long long i = 0 ; i < n ; i++)
        {
            sum+=nums[i];
            if(sum >= k)
            {
                shortest = min(shortest,i+1);
            }
            pair<long long,long long>curr = {INT_MIN,INT_MIN};
            
            while(!dq.empty() && ((sum-dq.front().second)>=k))
            {
                curr = dq.front();
                dq.pop_front();
            }
            if(curr.second!=INT_MIN)
            {
                shortest = min(shortest , i-curr.first);
            }
            while(!dq.empty() && dq.back().second>=sum)
            {
                dq.pop_back();
            }
            dq.push_back({i,sum});
        }
        return shortest==INT_MAX?-1:shortest;
        
        
    }
};