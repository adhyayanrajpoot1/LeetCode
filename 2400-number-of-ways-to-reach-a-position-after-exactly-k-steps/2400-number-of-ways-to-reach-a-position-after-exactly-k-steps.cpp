
const int mod=(int)1e9+7;


class Solution {
public:
    int dp[3007][3007];
    int f(int s , int e ,int k)
    {
        
        if(k==0){
            if(s==e){
                cout<<s <<endl;
                return 1;
            }
            return 0;
        }
        if(k<0)return 0;
        if(dp[s+1000][k]!=-1)return dp[s+1000][k];
        //if(pos.find(st)!=pos.end())return pos[st]%100000007;
        
         return dp[s+1000][k]= (f(s+1,e,k-1)%mod+f(s-1,e,k-1)%mod)%mod;
        //cout<<ans<<endl;
       // return pos[st]=ans;
    }
    int numberOfWays(int s, int e, int k) {
        memset(dp, -1, sizeof dp);
        return f(s,e,k)%mod;
        
    }
};