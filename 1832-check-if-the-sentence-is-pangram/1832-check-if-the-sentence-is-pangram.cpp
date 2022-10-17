class Solution {
public:
    bool checkIfPangram(string sentence) {
        set<char>s;
        for(int i = 0 ; i < 26 ; i++)
        {
            s.insert(i);
        }
        for(auto it : sentence)
        {
            s.erase(it-'a');
            
        }
        return s.size()==0;
    }
};