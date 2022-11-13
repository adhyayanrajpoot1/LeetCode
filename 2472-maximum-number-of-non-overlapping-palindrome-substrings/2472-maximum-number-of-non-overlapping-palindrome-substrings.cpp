class Solution {
public:
   int maxPalindromes(string s, int k) {
    int n = s.size(), ans = 0, start = 0;
    for (int center = 0; center < 2 * n; center++) {
        int left = center / 2;
        int right = left + center % 2;
        while (left >= start && right < n && s[left] == s[right]) {
            if (right + 1 - left >= k) {
                ans++;
                start = right + 1;
                break;
            }
            left--; right++;
        }
    }
    return ans;
}
};