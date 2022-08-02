class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int >pq;
        for(auto it : nums)pq.push(it);
        int ans;
        while(k--){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};