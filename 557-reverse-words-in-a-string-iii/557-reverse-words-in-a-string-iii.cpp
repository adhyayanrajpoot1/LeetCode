class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string str;
        string ans="";
        while(ss>>str)
        {
            reverse(str.begin(),str.end());
            ans+=str;
            ans+=" ";
            
        }
        ans.pop_back();
        return ans;
    }
};