class Solution {
public:
    vector<vector<int>>visited;
    bool find(vector<vector<char>>& board, string word,int i,int j,int pos)
    {
        int n = board.size();
        int m = board[0].size();
        if(pos==word.length())return true;
        if(i>=n || i<0 ||j>=m || j<0 || visited[i][j]==1 || board[i][j]!=word[pos])return false;
        
        visited[i][j] = 1;
        bool ans =  find(board,word,i+1,j,pos+1)||find(board,word,i,j+1,pos+1)||find(board,word,i-1,j,pos+1)||find(board,word,i,j-1,pos+1);
        visited[i][j] = 0;
        
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        visited.resize(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(find(board,word,i,j,0))return true;
            }
        }
        return false;
    }
};