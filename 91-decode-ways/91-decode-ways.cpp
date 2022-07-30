
class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        int*dp = new int[n+1];
        if(s[0]=='0')dp[0]=0;
        else dp[0]=1;
        for(int i = 1; i < n ; i++)
        {
            //if both zeros
            if(s[i-1]=='0' and s[i]=='0'){
                dp[i] = 0;
            }
            //one is non zero other is not
            else if(s[i-1]!='0' and s[i]=='0')
            {
                if(s[i-1]=='1'||s[i-1]=='2')
                {
                    dp[i] = (i-2>=0?dp[i-2]:1);
                }
                else dp[i] = 0;
            }
            //one is zero and other is not
            else if(s[i-1]=='0' and s[i]!='0')
            {
                dp[i] = dp[i-1];
                //cout<<dp[i];
            }
            //both are non zero
            else{
                int num = stoi(s.substr(i-1 , 2));
                if(num<=26){
                    dp[i] = dp[i-1]+((i-2)>=0?dp[i-2] : 1);
                }
                else dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};