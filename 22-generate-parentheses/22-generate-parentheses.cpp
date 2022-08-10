class Solution {
public:
    void helper(int n , int ob , int cb , vector<string>&ans , string s)
    {
        if(ob==n && cb==n){
            ans.push_back(s);
            return;
        }
        if(ob<n){
            helper(n,ob+1,cb,ans,s+"(");
        }
        if(cb<ob){
            helper(n,ob,cb+1,ans,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(n,0,0,ans,"");
        return ans;
    }
};