class Solution {
public:
    string minWindow(string s, string t) {
        //if(s.size()<t.size())return "";
        int count= 0;
        unordered_map<char,int>m;
        for(auto it : t){
            if(m.find(it)==m.end())
            {
                count++;
            }
            m[it]++;
        }
        
        int i = 0;
        int j = 0;
        int start = 0;
        int ans = INT_MAX;
        while(j<s.size())
        {
        
            m[s[j]]--;
            
            if(m[s[j]]==0)
            {
                count--;
                if(count==0)
                {
                    while(count==0)
                    {
                        if(j-i+1<ans)
                        {
                            ans = j-i+1;
                            start = i;
                        }
                        m[s[i]]++;
                        if(m[s[i]]==1)count++;
                        i++;
                    }
                }
                
            }
            j++;
            
        }
        if(ans==INT_MAX)return "";
        return s.substr(start,ans);
        
        
        
    }
};