class Solution {
public:
   int dp[2001] = {};
bool pal[2001][2001] = {};
int dfs(int i, int k, string &s) {
    if (i >= s.size())
        return 0;
    if (!dp[i]) {
        dp[i] = 1 + dfs(i + 1, k, s);
        for (int j = i + k - 1; j < s.size(); ++j)
            if (pal[i][j])
                dp[i] = max(dp[i], 2 + dfs(j + 1, k, s));
        
    }
    return dp[i] - 1;
}
int maxPalindromes(string s, int k) {
    int n = s.size();
    for (int i = 0; i < n; ++i)
        pal[i][i] = true;
    for (int i = 0; i < n - 1; ++i)
        pal[i][i + 1] = (s[i] == s[i + 1]);
    for (int len = 3; len <= n; ++len)
        for (int i = 0, j = i + len - 1; j < n; ++i, ++j)
            pal[i][j] = pal[i + 1][j - 1] && (s[i] == s[j]);   
    return k == 1 ? s.size() : dfs(0, k, s);
}
};