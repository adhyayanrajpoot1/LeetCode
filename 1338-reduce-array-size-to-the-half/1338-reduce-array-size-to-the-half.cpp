class Solution {
public:
    int minSetSize(vector<int>& arr) {
        set<int>s;
        unordered_map<int,int>m;
        for(int i = 0 ; i < arr.size() ; i++)
        {
            m[arr[i]]++;
        }
        vector<pair<int,int>>ans;
        for(auto it : m){
            ans.push_back({it.second,it.first});
        }
        sort(ans.begin() , ans.end());
        int a = 0;
        int reduce = 0;
        int half = arr.size()/2;
        int i = ans.size()-1;
        while(reduce<half){
            reduce += ans[i].first;
            i--;
            a++;
        }
        return a;
    }
};