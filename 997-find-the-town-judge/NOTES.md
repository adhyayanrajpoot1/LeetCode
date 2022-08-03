Intuition:
Consider trust as a graph, all pairs are directed edge.
The point with in-degree - out-degree = N - 1 become the judge.
​
Explanation:
Count the degree, and check at the end.
​
Time Complexity:
Time O(T + N), space O(N)
​
​
Java:
​
public int findJudge(int N, int[][] trust) {
int[] count = new int[N+1];
for (int[] t: trust) {
count[t[0]]--;
count[t[1]]++;
}
for (int i = 1; i <= N; ++i) {
if (count[i] == N - 1) return i;
}
return -1;
}
C++:
​
int findJudge(int N, vector<vector<int>>& trust) {
vector<int> count(N + 1, 0);
for (auto& t : trust)
count[t[0]]--, count[t[1]]++;
for (int i = 1; i <= N; ++i) {
if (count[i] == N - 1) return i;
}
return -1;
}