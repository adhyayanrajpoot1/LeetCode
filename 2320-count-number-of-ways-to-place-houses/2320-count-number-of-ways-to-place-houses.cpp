#define  ll long long;
class Solution {
public:
    long long find(int curr,int n,vector<vector<int>>&dp){
     if(n==1){
         return 1;
     }
     if(dp[n][curr]!=-1) return dp[n][curr];
     int one=0;
     int zero=find(0,n-1,dp);
     if(curr!=1){
         one=find(1,n-1,dp);
     }
     return dp[n][curr]=(one + zero)%mod;
 }
    
    int mod = 1e9+7;
    int  f(int pick , int ind,vector<vector<int>>&dp)
    { 
        if(ind==1)
        {   
            return 1;
        }
        if(dp[ind][pick]!=-1)return dp[ind][pick];
        int place = 0;
        int notPlace = f(0,ind-1,dp);
        if(pick!=1)
        {
            place = f( 1,ind-1,dp);
        }
        return dp[ind][pick] = (place+notPlace)%mod;
    }
    
    int countHousePlacements(int n) {
        vector<vector<int>>dp(n+1,vector<int>(2,-1));

     long long t =  (f(0,n,dp) +f(1,n,dp))%mod;
        return (t*t)%mod;
        //vector<vector<int>>dp(n+2,vector<int>(2,-1));
        //int total =  f(n,0,n,dp) +f(n,1,n,dp);
        //return total*total;
    }
};