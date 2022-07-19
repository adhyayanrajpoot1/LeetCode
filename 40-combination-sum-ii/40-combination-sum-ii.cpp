class Solution {
public:
    
    void f(int ind , int t , vector<int>& can, vector<vector<int>>&ans,vector<int>&v)
    {
        //base case
        if(ind==can.size())
        {
            if(t==0){
            ans.push_back(v);}
            return;
        }
        if(ind>=can.size())return;
        
        
        
        //pick 
        if(can[ind]<=t)
        {
            v.push_back(can[ind]);
            
            
            f(ind+1,t-can[ind],can,ans,v);
            v.pop_back();
            
        }
        while(ind+1<can.size() && can[ind]==can[ind+1])ind++;
        f(ind+1,t,can,ans,v);
        
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        f(0,target,candidates,ans,v);
        return ans;
    }
};