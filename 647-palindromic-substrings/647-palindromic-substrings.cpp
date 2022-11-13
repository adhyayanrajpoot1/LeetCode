class Solution {
public:
    bool isPalind(string &str)
    {
        int i = 0 ;
        int j = str.size()-1;
        while(i<j)
        {
            if(str[i]!=str[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int c=0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            for(int j = i ; j<s.size() ; j++)
            {
                string str = s.substr(i,j-i+1);
                if(isPalind(str))c++;
            }
        }
        return c;
    }
};