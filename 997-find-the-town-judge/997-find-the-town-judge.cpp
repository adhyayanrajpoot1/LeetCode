class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> count(N + 1, 0);
    for (auto& t : trust)
        count[t[0]]--, count[t[1]]++;
    for (int i = 1; i <= N; ++i) {
        if (count[i] == N - 1) return i;
    }
    return -1;
}
    // void dfs(int n, vector<vector<int>>& trust,vector<bool>&visited)
    // {
    //     for(int i =0 ; i < trust.size() ; i++)
    //     {
    //         if(visited[trust[i][0]]==false)
    //         {
    //             //cout << visited[trust[i][0]] << ' ';
    //             visited[trust[i][0]] = true;
    //         }
    //     }
    // }
    // int findJudge(int n, vector<vector<int>>& trust) {
    //     vector<bool>visited(n+1,false);
    //     int size = trust.size();
    //     int ele=-1;
    //     dfs(n,trust,visited);
    //     //bool isMany = false;
    //     for(int i = 1 ; i <= n ; i++)
    //     {
    //         if(size > 0 && visited[i]==false)
    //         {
    //             if(ele==-1)
    //                 ele = i;
    //             else return -1;
    //         }
    //     }
    //     if(size==0 && n==1)return 1;
    //     return ele;
    // }
};