class Solution {
public:
    string reverseVowels(string s) {
        set<char>st;
        st.insert('a');
        st.insert('e');
        st.insert('i');
        st.insert('o');
        st.insert('u');
        st.insert('A');
        st.insert('E');
        st.insert('I');
        st.insert('O');
        st.insert('U');
        
        int i = 0; 
        int j = s.size();
        while(i<j)
        {
            
            if(st.find(s[i])!=st.end() && st.find(s[j])!=st.end())
            {
                char ch = s[i];
                s[i] = s[j];
                s[j] = ch;
                i++;
                j--;
            }
            else if(st.find(s[i])!=st.end())j--;
            else if(st.find(s[j])!=st.end())i++;
            else{
                i++;
                j--;
            }
            
        }return s;
    }
};