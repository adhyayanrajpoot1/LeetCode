auto iter = lower_bound(begin(dp), end(dp), n);
if (iter == end(dp))
{
dp.push_back(n);
continue;
}
if (*iter > n)
*iter = n;
}
return dp.size();
Apparently, as you may have already noticed, the "dp" here contains at most 2 elements, so one instant simplification here is to replace "lower_bound" call to a simple "if comparison else comparison". Then a much more simplified version is obtained:
​
class Solution {
public:
bool increasingTriplet(vector<int>& nums) {
int a = INT_MAX, b = INT_MAX;
for (auto n : nums)
if (n <= a)
a = n;
else if (n <= b)
b = n;
else
return true;
return false;
}
};
You may have seen 100 ways to explain why this "if .. else" works in other discussions. Here, it is so easy to understand: it is just a simple version of Binary Search for 2 elements -- the replacement of lower_bound in above solution.