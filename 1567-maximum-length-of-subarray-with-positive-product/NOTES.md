Approach
I would suggest to first solve https://leetcode.com/problems/maximum-product-subarray/.
This solution is based on the concepts of this previous, more trivial/standard question.
Anyways, I wil explain assuming you haven't solved it :)
​
This question enquires about the longest positive value product. Let's first assume that input array consists of only non-negative numbers. This question has a trivial solution, we can traverse the array in linear time while maintaining a counter for the current longest chain of positive numbers. If we get a zero value in the array, We reset the counter to zero.
The maximum value of this counter at any point of time during this operation will be the answer.
​
Now comes the tricky part, what if there are negative numbers?
In this case, we will need to maintain two counters, one for the current longest chain of positive numbers and another for the current longest chain of negative numbers.
While traversing the array,
​
If we get a positive number, Increment the counters by one.
If we get a negative number, Exchange the longest positive and negative chain's counter's values.
If we get zero, Reset both counters to zero.
There is a small flaw with this though, what if we get the following array, A = [1,2,3,4,-5]. We should not increment the negative chain's counter value here until index 4, as the product will always remain positive. Conversely, we get A = [-1, 2, 3]. We should not increment the positive counter at index 0.
​
To tackle this problem, Upon getting a positive number in the array increment the negative counter only if the size of negative chain was already non-zero. Conversely, do the same for the positive counter.
​
Solution
class Solution {
public:
int getMaxLen(vector<int>& nums) {
int pos = 0, neg=0, temp, ans=0;
for(int i=0;i<nums.size();i++){
if(nums[i] == 0){
pos = 0;
neg = 0;
}
else if(nums[i] > 0){
pos++;
if(neg>0)
neg++;
}
else{
if(neg>0)
temp = neg + 1;
else
temp = 0;
neg = pos+1;
pos = temp;
}
ans = max(ans, pos);
}
return ans;
}
};
Complexity
Time complexity - O(n)
Space complexity - O(1)