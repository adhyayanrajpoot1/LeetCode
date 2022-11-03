// a palindrome is a string that reads the same forward and backward
// e.g. "aa", "abba", "aaaa", "lcggcl", etc ...
// we can see that the left half part is the reversed version of the right half part
// e.g. "a | a", "ab | ba", "aa | aa", "lcg | gcl", etc ...
// for example, if we have "ab" and "ba", we can form "abba" which is a palindrome
// and if we have "lc" and "cl", we can form "lccl"
// and we can add it to the previous palindrome in the middle place to make it longer
// e.g. ab[lccl]ba -> ablcclba

// case 1: the word is not same as the reversed self, e.g. "ab" != "ba"
// in this case, we need its reveresd string, i.e. ba to form "abba" as a palindrome

// case 2: the word is same as the reversed self, e.g. "aa" == "aa"
// case 2.1: if it is even, we could place it in the middle or on the side
// e.g. [aa]abba[aa]
// case 2.2: if the frequency of "aa" is odd, we could only place it in the middle
// e.g. ab[aa]ba
// since even + 1 = odd, we can put all even "aa" on the side, and put one in the middle
// e.g. [aa]ab[aa]ba[aa]

// class Solution {
// public:
//     // to reverse a string, there are multiple ways to do it
//     // in this example, STL reverse will be used
//     string reversed(string s) {
//         string t = s;
//         reverse(t.begin(), t.end());
//         return t;
//     }
//     int longestPalindrome(vector<string>& words) {
//         int ans = 0, middle = 0;
//         // count the frequency of each word
//         unordered_map<string, int> cnt;
//         for (auto word : words) cnt[word]++;
//         for (auto [s, f] : cnt) {
//             // using rev(s) is just to generalise the solution
//             // in this problem, we can just check if s[0] != s[1]
//             string rev = reversed(s);
//             if (s != rev) {
//                 // case 1: the word is not same as the reversed self, e.g. "ab" != "ba"
//                 // find the reversed self
//                 if (cnt.count(rev)) {
//                     // if it can be found, 
//                     // then we can only include the min of their counts
//                     // e.g. "ab", "ba", "ba", "ba"
//                     // we can only form "abba" as we don't have enough "ab" for the rest of "ba"
//                     // p.s `cnt[s]` is same as `f`
//                     ans += min(cnt[s], cnt[rev]);
//                 }
//                 // Alternatively, you can use STL
//                 // auto it = cnt.find(rev);
//                 // if (it != cnt.end()) ans += min(f, it->second);
                
//             } else {
//                 // case 2: both character are same, e.g. aa
//                 // we can put it on both side
//                 ans += f;
//                 // however, if the frequency is odd
//                 if (f & 1) {
//                     // we can place one in the middle and others on the side
//                     middle = 1;
//                     ans -= 1;
//                 }
//             }
//         }
//         ans += middle;
//         // at the end, we need to multiply the answer by 2
//         // e.g. if frequency of "aa" is 2, the longest palindrome is 4 ("aaaa")
//         return 2 * ans;
//     }



class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>m;
        for(auto it : words)
        {
            m[it]++;
        }
        int count=0;
        int middle = 0;
        for(auto all : m)
        {
            string it = all.first;
            string st = it;
            reverse(it.begin(),it.end());
            if(st == it)
            {
                count+=m[st];
                if(m[st]&1)
                {
                    middle=1;
                    count-=1;
                    //cout<<"bfs";
                }
            }
            else
            {
                if(m.find(it)!=m.end())
                {
                    count+=min(m[it],m[st]);
                }
            }
        }
        count+=middle;
        return (2*count);
    }
};