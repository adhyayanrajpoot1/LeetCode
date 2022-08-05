// recursive code starts -
dp[target] = 0;
// check for every element of nums. An element can only be taken if it is less than target.
// If an element is chosen, recurse for remaining value.
for(auto& num : nums)
if(num <= target) dp[target] += helper(nums, target - num, dp);
return dp[target];
}
Time Complexity : O(N * T), where N is the number of elements in nums and T is equal to the given target value.
​
Space Complexity : O(T). We need O(T) to maintain the dp array and in the worst case, we would have to do T numbers of recursive calls of helper. So, the overall space complexity becomes O(T).
​
✔️ Solution - III (Bottom-up Dynamic Programming)
​
The idea in this approach is also the same. We just start filling dp from curTarget = 1 all the way up to curTarget = target. At each curTarget, an element will be chosen if its value is less that target needed.
​
int combinationSum4(vector<int>& nums, int target) {
vector<uint> dp(target + 1); dp[0] = 1;
// start filling the dp array from bottom, i.e curTarget = 1 till target.
for (int curTarget = 1; curTarget <= target; curTarget++)
for (auto& num : nums)     // check for all elements from nums
if (num <= curTarget)  // an element will only be taken if it is less than target to be achieved
// the optimal answer(no. of combination) of remaining value is added to dp[curTarget]
dp[curTarget] += dp[curTarget - num];
return dp[target];
}
Time Complexity : O(N * T)
​
Space Complexity : O(T). Although the space complexity remains the same, we are saving the space requried by implicit recursive stack.
​
✔️ Solution IV (Slightly efficient version of Solution - III)
​
The above solution will always loop for N times for each curtarget from 1 to target. We could achieve slightly better performance if we sort the array at start and break as soon as nums[i] becomes greater than curTarget in the inner loop. The same optimization can be done for Top-Down approach of Solution - II as well.
​
int combinationSum4(vector<int>& nums, int target) {
sort(begin(nums), end(nums));
vector<uint> dp(target + 1); dp[0] = 1;
for (int curTarget = 1; curTarget <= target; curTarget++)
for (auto& num : nums)
if (num <= curTarget)  dp[curTarget] += dp[curTarget - num];
else break;
return dp[target];
}
Time Complexity : O(N*T). Although the time complexity remains same, the performance would be better in most cases since we wouldn't need to loop N times for every curTarget
​
Space Complexity : O(T)