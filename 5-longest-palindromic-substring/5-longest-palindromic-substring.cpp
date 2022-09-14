class Solution {
public:
    bool pal(string &str)
    {
        int l = 0;
        int r = str.size()-1;
        while(l<=r)
        {
            if(str[l]!=str[r])return false;
            l++;
            r--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string str;
        int maxi = 0;
        int n = s.size();
        vector<vector<int>>v(s.size() , vector<int>(s.size(),0));
        for(int diff = 0 ; diff < s.size() ; diff++)
        {
            for(int i = 0 , j = i+diff ; j<n && i<n ; i++,j++)
            {
                if(i==j)
                {
                    v[i][j] = 1;
                }
                else if(diff==1)
                {
                    v[i][j] = (s[i]==s[j])?2:0;
                }
                else 
                {
                    if(s[i]==s[j] && v[i+1][j-1])
                        v[i][j] = v[i+1][j-1]+2;
                }
                
                if(v[i][j])
                {
                    if(j-i+1>maxi)
                    {
                        maxi = j-i+1;
                        str = s.substr(i,maxi);
                    }
                }
            }
        }
        return str;
        
        
        
        
        // int maxi = 0;
        // string ans;
        // for(int i = 0; i < s.length() ; i++)
        // {
        //     for(int j = i ; j < s.length() ; j++)
        //     {
        //         string x = s.substr(i,j-i+1);
        //         if(pal(x))
        //         {
        //             if(j-i+1>maxi)
        //             {
        //                 maxi = j-i+1;
        //                 ans = s.substr(i,j-i+1);
        //             }
        //            // maxi = max(maxi,j-i+1);
        //         }
        //     }
        // }
        // return ans;
    }
};