class Solution {
public:
    vector<int> gridIllumination(int n, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        unordered_map<int,unordered_set<int>>m;
        unordered_map<int,int>rd , ld , c, r;
        for(auto it : lamps)
        {
            int i = it[0];
            int j = it[1];
            if(m[i].insert(j).second)rd[i-j]++ , ld[i+j]++ , c[j]++,r[i]++;
        }
        vector<int>ans;
        for(auto it : queries)
        {
            int i = it[0];
            int j = it[1];
            if(r[i] || c[j] || ld[i+j] || rd[i-j])
            {
                ans.push_back(1);
                for(int ii = i -1 ; ii<= i+1 ; ii++)
                {
                    for(int jj = j-1 ; jj<= j+1 ; jj++)
                    {
                        if(m[ii].erase(jj))--r[ii] , --c[jj] , --rd[ii-jj],--ld[ii+jj];
                    }
                }
            }
            else ans.push_back(0);
        }
        return ans;
        
    }
};