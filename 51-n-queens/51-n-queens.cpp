class Solution {
public:
    //vector<vector<string>>ans;
    void helper(int i , int n , vector<string>&board , vector<vector<string>>&ans,vector<int>&tl , vector<int>&tr , vector<int>&col)
    {
        if(i==n){
            ans.push_back(board);
            return;
        }
        
        for(int j = 0 ; j < n ; j++)
        {
            if(tl[i-j+n-1] ==0 && !tr[i+j] && !col[j])
            {
                board[i][j] = 'Q';
                col[j] = tr[i+j] = tl[i-j+n-1]=1;
                helper(i+1,n,board,ans,tl,tr,col);
                board[i][j] = '.';
                col[j] = tr[i+j] = tl[i-j+n-1]=0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>arr;
        vector<string>board(n);
        string s(n,'.');
        vector<int>tl(2*n,0) , tr(2*n,0) , col(n,0);
        for(int i = 0 ; i < n ; i++)
        {
            board[i]=s;
        }
        helper(0,n,board,arr,tl,tr,col);
        return arr;
    }
};