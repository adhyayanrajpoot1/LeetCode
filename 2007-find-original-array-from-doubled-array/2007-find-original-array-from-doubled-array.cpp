class Solution {
public:
//     vector<int> findOriginalArray(vector<int>& changed) {
//         map<int,int>m;
//         vector<int>ans;
//         int n = changed.size();
//         if(n%2)return {};
//         for(auto it : changed)m[it]++;
//         sort(changed.begin(),changed.end());
//         for(auto it : changed)
//         {
//             if(m[it]==0)continue;
//             if(m[it*2]==0)return {};
//             ans.push_back(it);
//             m[it]--;
//             m[it*2]--;
//         }
//         return ans;
        
//     }
     vector<int> findOriginalArray(vector<int>& A) {
        if (A.size() % 2) return {};
        unordered_map<int, int> c;
        for (int a : A) c[a]++;
        vector<int> keys;
        for (auto it : c)
            keys.push_back(it.first);
        sort(keys.begin(), keys.end(), [](int i, int j) {return abs(i) < abs(j);});
        vector<int> res;
        for (int x : keys) {
            if (c[x] > c[2 * x]) return {};
            for (int i = 0; i < c[x]; ++i, c[2 * x]--)
                res.push_back(x);
        }
        return res;
    }
};