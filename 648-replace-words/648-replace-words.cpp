class TrieNode{
  public:
    TrieNode*arr[26];
    bool isEdge;
    TrieNode()
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            arr[i] = NULL;
        }
        isEdge = false;
    }
};
class Solution {
public:
    TrieNode*node = new TrieNode();
    void insert(string s)
    { TrieNode*root=node;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(root->arr[s[i]-'a']==NULL)root->arr[s[i]-'a'] = new TrieNode();
            root=root->arr[s[i]-'a'];
        }
        root->isEdge = true;
    }
    string find(string s)
    {
        TrieNode*root=node;
        string str="";
        for(int i = 0 ; i < s.size() ; i++)
        {   
            if(root->arr[s[i]-'a']==NULL)break;
            str+=s[i];
            root=root->arr[s[i]-'a'];
            if(root->isEdge)return str;
            
        }
        return s;
    }
    

    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string str;
        string ans="";
        for(auto it : dictionary)
        {
            insert(it);
        }
        
        while(ss>>str)
        {
            string a = find(str);
            ans+=a;
            ans+=" ";
            
        }
        ans.pop_back();
        return ans;
    }
};