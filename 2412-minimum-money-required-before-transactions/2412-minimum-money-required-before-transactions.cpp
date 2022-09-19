class Solution {
public:
        long long minimumMoney(vector<vector<int>>& A) {
        long long res = 0; int v = 0;
        for (auto& a : A) {
            v = max(v, min(a[0], a[1]));
            res += max(a[0] - a[1], 0);
        }
        return res + v;
    }
};
// Intuition
// The worst case is losing all money first,
// then we earn money later.


// Explanation
// First we calculate the sum of all money we can lose.
// That is the sum of lost money is
// sum_lose = sum(max(0, cost[i] - cashback[i]))

// Assume before the last transaction thet lose money,
// we have money = cost[i],
// we spent all money as cost for this transaction,
// we have no money left.
// After transaction, we have money = cashback[i].

// So the initial money is at least sum_lose + cashback[i]
// and after all losing money,
// we need at least max(cost[i]),
// where cost[i] is the cost for all earning money transaction.


// Complexity
// Time O(n)
// Space O(1)
