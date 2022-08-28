class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
    vector<int> ans;
    int n=arr.size();
    stack<pair<int,int>> st;
    for(int i=0;i<n;i++){
        if(st.empty()){
            ans.push_back(-1);
        }
        else if(arr[i]>st.top().first){
            ans.push_back(st.top().second);
        }
        else{
            while(st.size()!=0 && arr[i]<=st.top().first){
               st.pop(); 
            }
            if(st.empty()){
                ans.push_back(-1);
            }
            else{
                ans.push_back(st.top().second);
            }
        }
        st.push({arr[i],i});
    }
    vector<int> ans1;
   stack<pair<int,int>> st1;
    for(int i=n-1;i>=0;i--){
        if(st1.empty()){
            ans1.push_back(n);
        }
        else if(arr[i]>st1.top().first){
            ans1.push_back(st1.top().second);
        }
        else{
            while(st1.size()!=0 && arr[i]<=st1.top().first){
               st1.pop(); 
            }
            if(st1.empty()){
                ans1.push_back(n);
            }
            else{
                ans1.push_back(st1.top().second);
            }
        }
         st1.push({arr[i],i});
    }
    reverse(ans1.begin(),ans1.end());
    int sum=0;
    for(int i=0;i<n;i++){
        int ind=ans1[i]-ans[i]-1;
        sum=max(sum,ind*arr[i]);
    }
    return sum;
}
    int maximalRectangle(vector<vector<char>>& mat) {
        vector<int> v;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<m;i++){
            v.push_back(mat[0][i]-'0');
        }

        int mx=largestRectangleArea(v);
            for(int i=1;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j]=='0')
                        v[j]=0;
                    else{
                        v[j]+=mat[i][j]-'0';

                    }
                }
                mx=max(mx,largestRectangleArea(v));
            }
        return mx;
    }
};