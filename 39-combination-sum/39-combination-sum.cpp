class Solution {
public:
    vector<int>v;
    void f(int ind , int target , vector<int>&can,vector<vector<int>>&ans)
    {
        
        // if(ind==can.size())
        // {
        //     if(target==0){
        //         ans.push_back(v);
        //     }
        //     return;
        // }
        if(target==0){
            ans.push_back(v);
            return;
        }
        //if(target<0)return;
        if(ind>=can.size())return;
        if(can[ind]<=target)
        {
            v.push_back(can[ind]);
            f(ind,target-can[ind],can,ans);
            v.pop_back();
        }
        f(ind+1,target,can,ans);
        
    }
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>>ans;
        f(0,target,c,ans);
        return ans;
    }
};