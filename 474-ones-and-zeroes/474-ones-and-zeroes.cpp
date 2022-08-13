class Solution {
public:
    vector<vector<vector<int>>>dp;
    
    int f(vector<string>& strs ,int i , int m , int n) {
        if(i == strs.size())return 0;
        int &ans = dp[i][m][n];
        if(ans!=-1)return ans;
        int zeros = count(strs[i].begin() , strs[i].end() , '0');
        int ones = strs[i].size() - zeros;
        
        if(m-zeros >=0 && n-ones>=0){
            return ans = max(1+f(strs , i+1 , m-zeros , n-ones) , f(strs , i+1,m,n));
            
        }
        return ans = f(strs , i+1,m,n);
        
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.resize(strs.size()+1 , vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return f(strs,0,m,n);
    }
};