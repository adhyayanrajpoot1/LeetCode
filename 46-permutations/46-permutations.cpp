class Solution {
public:
    
    void f(vector<int>& nums ,vector<vector<int>>&ans , vector<int>&smallAns,vector<int>&freq)
    {
        //base case
        if(smallAns.size()==freq.size())
        {
            ans.push_back(smallAns);
            return;
        }
        for(int i = 0 ; i < freq.size();i++)
        {
            if(!freq[i])
            {
                freq[i]=1;
                smallAns.push_back(nums[i]);
                f(nums,ans,smallAns,freq);
                smallAns.pop_back();
                freq[i]=0;
            }
        }
        
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int size = 1<<n;
        vector<vector<int>>ans;
        vector<int>freq(n,0);
        vector<int>smallAns;
        f(nums,ans,smallAns,freq);
        return ans;
    }
};