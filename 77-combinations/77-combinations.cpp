class Solution {
public:
    void f(int n, int k , int i , vector<int>&subset,vector<vector<int>>&ans)
    {
        
        if(k==0){
            ans.push_back(subset);
            return;
        }
        if(i>n)return ;
        
        //pick 
        subset.push_back(i);
        f(n,k-1,i+1,subset,ans);
        subset.pop_back();
        f(n,k,i+1,subset,ans);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>subset;
        vector<vector<int>>ans;
        f(n,k,1,subset,ans);
        return ans;
    }
};