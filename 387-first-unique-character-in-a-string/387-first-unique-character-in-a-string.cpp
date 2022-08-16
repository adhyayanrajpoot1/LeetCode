class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int>mapp;
        for(int i = 0 ; i < s.size() ; i++)
        {
            mapp[s[i]]++;
            
        }
        int index = -1;
        for(int i= 0; i < s.size() ; i++)
        {
            if(mapp[s[i]]==1){
                index = i;
                break;
            }
            
        }
//         int i = 0;
//         for(auto it : s){
//             if(mapp[it]==1) {
//                 break;
//             }
//             else {
//                 //index = i;
//                 continue;
                
//             }
//             cout << "fvskfbn"<<endl;
//             i++;
//         }
        return index;
    }
};