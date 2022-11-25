class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>sl(n) , sr(n);
        stack<int>s1,s2;
        for(int i = 0 ; i < n ; i++)
        {
            sl[i] = i;
            sr[i] = n-i-1;
        }
        for(int i = 0 ; i < n ; i++)
        {
            while(!s1.empty() && arr[s1.top()]>arr[i])
            {
                sr[s1.top()] = i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i = n-1 ; i>= 0 ; i--)
        {
            while(!s2.empty() && arr[s2.top()]>=arr[i])
            {
                sl[s2.top()] = s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        int mod = 1e9+7;
        long long ans= 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            long long a = (sl[i]+1)%mod;
            long long b = (sr[i]+1)%mod;
            ans+=(arr[i]*(a)*(b));
            ans%=mod;
        }
        return ans;
        
    }
};