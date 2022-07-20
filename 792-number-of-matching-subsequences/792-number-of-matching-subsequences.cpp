class Solution {
public:
    
    int numMatchingSubseq(string s, vector<string>& words){
        
        int n = s.size();
        int m = words.size();
        unordered_map<char,vector<int>>mapp;
        int count=0;
        
        for(int i = 0 ; i < n ; i++)
        {
            mapp[s[i]].push_back(i);
        }
        for(auto it : words)
        {
            int size = it.size();
            int counter = -1;
            for(int i = 0 ; i < size;i++)
            {
                auto iter = upper_bound(mapp[it[i]].begin(),mapp[it[i]].end(),counter);
                if(iter==mapp[it[i]].end())break;
                counter=*iter;
                if(i==it.size()-1)count++;
                
            }
           // count++;
        }
        return count;
        
        
        
    }
    
    
//     bool brute(string s1 , string s2)
//     {
//         int n = s1.size();
//         int m =s2.size();
//         if(m>n)return false;
        
//         int i= 0 , j = 0;
//         while(i<n && j<m)
//         {
//             if(s1[i]==s2[j]){
//                 i++;
//                 j++;
//             }
//             else i++;
//         }
//         if(j!=m)return false;
//         return true;
//     }
//     int numMatchingSubseq(string s, vector<string>& words) {
//         int count=0;
//         for(auto it: words)
//         {
//             if(brute(s,it))count++;
//         }
//         return count;
//     }
};