https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/discuss/1322101/C%2B%2BJavaPython-MaxHeap-MinHeap-Binary-Search-Picture-Explain-Clean-and-Concise
​
​
​
✔️ Solution 1: Max Heap keeps up to k elements
​
The easy approach is that we iterate all elements in the matrix and and add elements into the maxHeap. The maxHeap will keep up to k smallest elements (because when maxHeap is over size of k, we do remove the top of maxHeap which is the largest one). Finally, the top of the maxHeap is the kth smallest element in the matrix.
This approach leads this problem become the same with 215. Kth Largest Element in an Array, which doesn't take the advantage that the matrix is already sorted by rows and by columns.
class Solution { // 28 ms, faster than 83.06%
public:
int kthSmallest(vector<vector<int>> &matrix, int k) {
int m = matrix.size(), n = matrix[0].size(); // For general, the matrix need not be a square
priority_queue<int> maxHeap;
for (int r = 0; r < m; ++r) {
for (int c = 0; c < n; ++c) {
maxHeap.push(matrix[r][c]);
if (maxHeap.size() > k) maxHeap.pop();
}
}
return maxHeap.top();
}
};
​
Complexity:
Time: O(M * N * logK), where M <= 300 is the number of rows, N <= 300 is the number of columns.
Space: O(K), space for heap which stores up to k elements.
✔️ Solution 2: Min Heap to find kth smallest element from amongst N sorted list
​
Since each of the rows in matrix are already sorted, we can understand the problem as finding the kth smallest element from amongst M sorted rows.
We start the pointers to point to the beginning of each rows, then we iterate k times, for each time ith, the top of the minHeap is the ith smallest element in the matrix. We pop the top from the minHeap then add the next element which has the same row with that top to the minHeap.
image
​
class Solution { // 124 ms, faster than 5.10%