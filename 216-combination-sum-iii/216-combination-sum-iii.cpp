class Solution {
public:
    vector<vector<int>>ans;
    void f( int sum , int tar , int k ,vector<int>&ds,int num)
    {
        if(tar<sum)return;
        if(tar==sum)
        {
            if(k==0)
                ans.push_back(ds);
            return;
        }
        //if(ind==nums.size())return;
        if(num>9)return;
        ds.push_back(num);
        sum+=num;
        f( sum,tar,k-1,ds,num+1);
        ds.pop_back();
        sum-=num;
        f(sum,tar,k,ds,num+1);
            
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        //vector<int>nums(9);
        //iota(nums.begin() , nums.end(),1);
        vector<int>temp;
        f(0,n,k,temp,1);
        return ans;
    }
};