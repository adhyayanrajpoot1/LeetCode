class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);
        string str;
        string ans="";
        while(ss >> str)
        {
            if(ans!="")
            ans = str+" "+ans;
            else
                ans = str;
        }
        return ans;
    }
};