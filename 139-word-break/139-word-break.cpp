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
        memset(dp,-1,sizeof dp);
        for(auto it : wordDict)
        {
            st.insert(it);
        }
        return f(0,s,st);
        
    }
    
   
};