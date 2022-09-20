class Solution {
public:
    bool has(int i, int j ,int n,int m, vector<vector<char>>& board,string&word , int p)
    {
        if(p==word.length())return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[p])return false;
        board[i][j]='#';
        bool var1 = has(i,j+1,n,m,board,word,p+1);
        bool var2 = has(i,j-1,n,m,board,word,p+1);
        bool var3 = has(i+1,j,n,m,board,word,p+1);
        bool var4 = has(i-1,j,n,m,board,word,p+1);
        board[i][j]=word[p];
        return var1||var2||var3||var4;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < m ;j++)
            {
                if(has(i,j,n,m,board,word,0))return true;
                else continue;
            }
        }
        return false;
    }
};