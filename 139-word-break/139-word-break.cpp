class Solution {
public:
    int dp[301];
    int f(int i , string s , set<string>&st)
    {
        if(i==s.size())return 1;
        if(dp[i]!=-1)return dp[i];
        string temp="";
        for(int j = i ; j < s.size() ; j++)
        {
            temp+=s[j];
            if(st.find(temp)!=st.end())
            {
                if(f(j+1,s,st))return dp[i]= 1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string>st;
        memset(dp,0,sizeof dp);
        for(auto it : wordDict)
        {
            st.insert(it);
        }
        // return f(0,s,st);
        int n = s.size();
        dp[n]=1;
        for(int i = n-1 ; i>=0 ; i--)
        {
            string temp="";
            for(int j = i ; j < n ; j++)
            {
                temp+=s[j];
                if(st.find(temp)!=st.end())
                {
                    cout << temp << " ";
                    if(!dp[i])
                    dp[i] = dp[j+1];   
                    //break;
                }
                //else dp[i] = 0;   
            }    
        }
        cout << st.count("a")<<endl;
        for(int i = 0 ; i <= s.size() ; i++)
        {
            cout << dp[i] << " ";
        }
        return dp[0];
        
    }
    
   
};