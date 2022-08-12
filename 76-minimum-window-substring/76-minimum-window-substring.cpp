class Solution {
public:
    string minWindow(string s , string t) {
        int n = s.length();
        int m = t.length();
        if(n<m)return "";
        unordered_map<char,int>mp;
        for(auto it : t) mp[it]++;
        int i = 0 , j = 0, mn = n+1 , count= mp.size();
        string res = s;
        while(j<n) {
            if(mp.find(s[j])!=mp.end()) {
                mp[s[j]]--;
                if(mp[s[j]]==0)count--;
            }
            if(count==0) {
                while(count==0 && i<=j) {
                    if(mp.find(s[i])!=mp.end()) {
                        mp[s[i]]++;
                        if(mp[s[i]]==1){
                            if(mn > j-i+1){
                                mn = j-i+1;
                                res = s.substr(i,mn);
                            }
                            count++;
                        }
                    }
                    i++;
                }
            }
            j++;
        }
        if(mn==n+1)return "";
        return res;
    }
//     string minWindow(string s, string t) {
//         if(s.length()<t.length())
//             return "";
        
//         unordered_map<char,int>umap;
//         int i=0,j=0,mn=s.size()+1,count=0;
//         string res="";
        
//         for(int i=0;i<t.length();i++)
//             umap[t[i]]++;
        
//         count=umap.size();
//         //SW
//         while(j<s.length()){
//             //cals
//             if(umap.find(s[j])!=umap.end()){
//                 umap[s[j]]--;
//                 //decrease count if val is 0
//                 if(umap[s[j]]==0)
//                     count--;
//             }

//             //window hit
//             if(count==0){
//                 // if(mn>j-i+1){
//                 //     mn=j-i+1;
//                 //     res=s.substr(i,mn);
//                 //     }
                
//                 while(i<=j && count==0){
//                     if(umap.find(s[i])!=umap.end()){
//                         umap[s[i]]++;
                        
//                         if(umap[s[i]]==1){
//                             if(mn>j-i+1){
//                                 mn=j-i+1;
//                                 res=s.substr(i,mn);
//                             }
//                             count++;
//                         }
//                     }
//                     i++;
//                 }
//             }
//             j++;
//         }
//         if(mn==INT_MAX)
//             return "";
//         return res;
//     }
};