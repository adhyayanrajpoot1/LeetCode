class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i]>='A' && s[i]<='Z')
            {
                str+=(s[i]-'A'+'a');
            }
            else if(s[i]>='a' && s[i]<='z')
            {
                str+=s[i];
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                str+=s[i];
            }
        }
        int i = 0 , j = str.size()-1;
        while(i<j)
        {
            if(str[i++]==str[j--])continue;
            return false;
        }
        return true;
    }
};