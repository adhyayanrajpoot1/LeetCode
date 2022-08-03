// class Solution {
// public:
//     bool wordPattern(string p, string s) {
//         stringstream check1(s);
//         string intermediate;
//         vector<string>v;
//         unordered_map<char,string>mp;
//         unordered_map<string,char>mp1;
//         int j =0;
//          set<char>s1;
//         set<string>s2;
//         while(getline(check1 , intermediate , ' '))
//         {
//             s2.insert(intermediate);
//             v.push_back(intermediate);
//         }
//        for(auto it : p)s1.insert(it);
//         for(int i=0; i < v.size() ; i++)
//         {
//             if(mp.find(p[j])!=mp.end() || mp1.find(v[i])!=mp1.end())
//             {
//                 if(mp[p[j]]==v[i] && mp1[v[i]]==p[j++])continue;
//                 else return false;
//             }
//             mp1[v[i]] = p[j];
//             mp[p[j++]] = v[i];
            
//         }
//         if(mp.size()<s1.size() || mp1.size()<s2.size())return false;
//         return true;
        
//     }
// };

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        
        istringstream in(s); 
        
        int i = 0, n = pattern.size();

        
        for(string word; in>>word; i++){
            if(i==n || p2i[pattern[i]] != w2i[word]) return false; //If it reaches end before all the words in string 's' are traversed || if values of keys : pattern[i] & word don't match return false
            
            p2i[pattern[i]] = w2i[word] = i+1; //Otherwise map to both to a value i+1
        }
        return i==n; //both the lengths should be equal
    }
};