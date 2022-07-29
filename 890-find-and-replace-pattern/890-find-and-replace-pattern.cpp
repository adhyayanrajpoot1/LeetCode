class Solution {
public:
    string F(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) m[c] = m.size();
        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
        return w;
    }
  vector<string> findAndReplacePattern(vector<string> words, string p) {
        vector<string> res;
        for (string w : words) if (F(w) == F(p)) res.push_back(w);
        return res;
    }
//     vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
//         int n = words.size();
//         int m = pattern.length();
//         unordered_map<char,vector<int>>mpO;
//         unordered_map<char,vector<int>>mp;
//         int i = 0;
//         for(auto it : pattern)
//         {
//             mpO[it].push(i++);
//         }
//         for(auto it : words)
//         {
//             int size=it.size();
//             if(size!=m)continue;
//             for(int i= 0 ; i< size ; i++)
//             {
//                 mp[it[i]].push(i);
//             }
//             for(int i = 0 ; i < mp.size();i++)
//             {
                
//             }
//         }
//     }
};


    