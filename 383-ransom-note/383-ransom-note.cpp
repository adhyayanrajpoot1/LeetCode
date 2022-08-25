class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>m1,m2;
        for(auto it : magazine){
            m1[it]++;
        }
        for(auto it : ransomNote){
            m2[it]++;
        }
        
        for(auto it : ransomNote)
        {
            if(m1[it]>=m2[it])continue;
            return false;
        }
        return true;
    }
};