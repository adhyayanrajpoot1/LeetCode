class Solution {
public:
    bool dfs(int i , int j , vector<vector<char>>&board , string&word,int &ind)
    {
        int n = board.size();
        int m = board[0].size();
        if(ind==word.size())return true;
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]=='#' )return false;
        
        char ch = board[i][j];
        
        bool ans = false;
        if(board[i][j]==word[ind])
        {
            board[i][j]='#';
            ind++;
            ans = dfs(i+1,j,board,word,ind)||dfs(i,j+1,board,word,ind)||dfs(i-1,j,board,word,ind)||dfs(i,j-1,board,word,ind);
            ind--;
            board[i][j] = ch;
        }
        
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
        int ind=0;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(i,j,board,word,ind))return true;
                }
            }
        }
        return false;
    }
};