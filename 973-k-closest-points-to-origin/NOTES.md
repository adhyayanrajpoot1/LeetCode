}
return ans;
}
private:
struct compare {
bool operator()(vector<int>& p, vector<int>& q) {
return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
}
};
};
We can also use a min heap. A min heap has the smallest element in the root. We add all the points to the heap, and then pop the first K ones, we are just the closest ones. This makes the code shorter. Now this one is of O(n + Klogn) time. The n part is on adding all points to the heap (building a min heap for all the points) and the Klogn part is on fetching the top K points from the heap.
​
class Solution {
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
priority_queue<vector<int>, vector<vector<int>>, compare> pq(points.begin(), points.end());
vector<vector<int>> ans;
for (int i = 0; i < K; i++) {
ans.push_back(pq.top());
pq.pop();
}
return ans;
}
private:
struct compare {
bool operator()(vector<int>& p, vector<int>& q) {
return p[0] * p[0] + p[1] * p[1] > q[0] * q[0] + q[1] * q[1];
}
};
};
Note that for priority_queue, if you would like to use it as a max heap, the comparator should be < and if as a min heap, the comparator is >.
​
Max/min heaps can also be implemented using multiset. For multiset, max heap has > and min heap has < in the comparator. The following two solutions are respectively max/min heap using multiset.
​
class Solution {
public:
vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
multiset<vector<int>, compare> mset;
for (vector<int>& point : points) {
mset.insert(point);
if (mset.size() > K) {
mset.erase(mset.begin());
}
}
vector<vector<int>> ans;
copy_n(mset.begin(), K, back_inserter(ans));
return ans;
}
private:
copy_n(mset.begin(), K, back_inserter(ans));