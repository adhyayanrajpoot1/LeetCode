We first transform the nums array into a points array that sums up the total number of points for that particular value. A value of x will be assigned to index x in points.
​
nums: [2, 2, 3, 3, 3, 4] (2 appears 2 times, 3 appears 3 times, 4 appears once)
points: [0, 0, 4, 9, 4] <- This is the gold in each house!
​
Credits for above explanation :- yangshun
​
int dp[10001];
int houseRobber(vector<int>& arr, int idx){
if(idx>=arr.size()) return 0;
if(dp[idx] != -1) return dp[idx];
return dp[idx] = max(arr[idx]+houseRobber(arr,idx+2),houseRobber(arr,idx+1));
}
int deleteAndEarn(vector<int>& nums) {
memset(dp,-1,sizeof dp);
vector<int> a(10001,0);
for(auto num : nums) a[num] += num;
return houseRobber(a,0);
}