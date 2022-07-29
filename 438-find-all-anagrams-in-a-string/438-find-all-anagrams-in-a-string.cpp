class Solution {
public:
vector<int> findAnagrams(string s, string p) {
unordered_map<char, int> mp;

//storing the occ. of string p in the map
for (auto &x : p){
    mp[x]++;
}
vector<int>ans;
int count = mp.size();
int k = p.size();
int i=0, j=0;

while (j < s.size()){
    //calculation part
    if (mp.find(s[j]) != mp.end()){
        mp[s[j]]--;
        if (mp[s[j]] == 0){
            count--;
        }
    }

    //window length not achived yet
    if (j-i+1 < k){
        j++;
    }

    //window length achived, find ans and slide the window
    else if (j-i+1 == k){
        //finding the ans
        if (count == 0){
            ans.push_back(i);
        }
        if (mp.find(s[i]) != mp.end()){
            mp[s[i]]++;
            if (mp[s[i]] == 1){
                count++;
            }
        }

        //slide the window
        i++;
        j++;
    }
}
return ans;
}
};



// class Solution {
// public:
//     vector<int> findAnagrams(string s, string t) {
//         vector<int>v;
//         int n = s.size();
//         int m = t.size();
//         int i = 0 , j =0;
//         unordered_map<char,int>mapp;
//         unordered_map<char,int>mapp2;
//         int ans = 0;
//         for(i = 0; i < n ; i++)
//         {
//             int count=0;
//             while(j-i+1<=m){
//                 if(mapp.find(t[j])!=mapp.end())
//                 {
//                     count++;
//                 }
//                 mapp[t[j]]++;
//                 j++;
//             }
//             if(j>m){
//                 mapp[s[i]]--;
//                 if(mapp[s[i]]==0)count--;
//                 if(count==0)ans++;
//                 cout<<ans<<" ";
//                 if(mapp[s[j]]==0)count++;
//                 mapp[s[j]]++;
//                 j++;
//                 //move the window
//                 i++;
//             }
//         }
//         // cout<<ans;
//         return v;
//     }
// };