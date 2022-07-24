class Solution {
public:
    int factorial(int n) {
        int factorial = 1;
        for (int i = 2; i <= n; i++)
            factorial = factorial * i;
        return factorial;
    }

    int nCr(int n, int r) {
        return factorial(n) / (factorial(r) * factorial(n - r));
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        unordered_map<long long,long long>mapp;
        for(int i = 0 ; i < nums.size() ;)
        {
            if(nums[i]==0)
            {
                int j = i;
                int count=1;
                while(j+1< nums.size() && nums[j]==nums[j+1])
                {
                    count++;
                    j++;
                }
                
                mapp[i] = count;
                i+=count;
            }
            else i++;
        }
        long long sum = 0 ;
        set<long long>s;
        long long n = nums.size();
        for(auto it : mapp)
        {
            //cout<<it.second;
            // for(int i = 0 ; i <=it.second ; i++)
            // {
                long long num = it.second;
                sum+=(num)*(num+1)/2;
                // cout << it.second-i << " ";
                // if(s.find(it.second-i)==s.end() ||i==0)
                // {
                // s.insert(i);
                // int num =
                // //cout<<num << " ";
                // sum+=num;
                
            
        }
        return sum;
        
    }
};