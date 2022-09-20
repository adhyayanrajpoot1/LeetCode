class TrieNode{
    public:
    string word;
    TrieNode*arr[26];
    bool end;
    TrieNode()
    {
        word="";
        for(int i = 0 ; i < 26 ; i++)
        {
            arr[i]=NULL;
        }
        end=0;
    }
};
class Solution {
public:
    TrieNode*root = new TrieNode();
    void insert(string s)
    {
        TrieNode*node = root;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(node->arr[s[i]-'a']==NULL)node->arr[s[i]-'a']= new TrieNode();
            node= node->arr[s[i]-'a'];
        }
        node->word = s;
        node->end = true;
    }
    vector<string>ans;
    void dfs(vector<vector<char>>& board , int i,int j , TrieNode*node)
    {
        if(board[i][j]=='$' || node->arr[board[i][j]-'a']==NULL)return;
        int n = board.size();
        int m = board[0].size();
        node = node->arr[board[i][j]-'a'];
        if(node->end>0)
        {
            //cout<<"sfnjb";
            ans.push_back(node->word);
            node->end = false;
        }
        //if(i<0 || i>=n || j<0 || j>=m )return;
        char ch = board[i][j];
        board[i][j] = '$';
        if(i<n-1)
        dfs(board,i+1,j,node);
        if(j<m-1)
        dfs(board,i,j+1,node);
        if(i>0)
        dfs(board,i-1,j,node);
        if(j>0)
        dfs(board,i,j-1,node);
        board[i][j] = ch;
        
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(auto it : words)
        {
            insert(it);
        }
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j =0 ; j < m ; j++)
            {
                dfs(board,i,j,root);
            }
        }
        return ans;
        
        
    }
};