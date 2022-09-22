class Solution {
public:
    //     int minSwaps(string s) {
    //     int cnt0 = count(begin(s), end(s), '0'), cnt1 = s.size() - cnt0, miss0 = 0, miss1 = 0;
    //     if (abs(cnt0 - cnt1) > 1)
    //         return -1;
    //     for (int i = 0; i < s.size(); i += 2) {
    //         miss0 += s[i] != '0';
    //         miss1 += s[i] != '1';
    //     }
    //     return cnt0 == cnt1 ? min(miss0, miss1) : cnt0 > cnt1 ? miss0 : miss1;
    // }
   
    int count(string& s, char c) {
        int miss = 0;
        for (int i = 0; i < s.length(); i += 2) {
            if (s[i] != c) miss++;
        }
        return miss;
    }
    int minSwaps(string s) {
        int cnt0 = 0, cnt1 = 0;
        for (char c : s) c == '0'? cnt0 += 1 : cnt1 += 1;
        if (abs(cnt0 - cnt1) > 1) return -1;
        
        if (cnt0 > cnt1) return count(s, '0');
        if (cnt0 < cnt1) return count(s, '1');
        return min(count(s, '0'), count(s, '1'));
    }

};