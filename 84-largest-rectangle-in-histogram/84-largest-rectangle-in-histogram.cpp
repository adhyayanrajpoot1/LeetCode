class Solution {
public:
    vector<int>a,b;
    void findNSleft(vector<int>&arr){
        int n = arr.size();
        stack<pair<int,int>>s;
        for(int i = 0 ; i < n ; i++)
        {
            if(i==0)b.push_back(-1);
            else if(!s.empty()&& arr[i]>s.top().second)
            {
                b.push_back(s.top().first);
            }
            else if(!s.empty()and arr[i]<=s.top().second)
            {
                while(!s.empty()and arr[i]<=s.top().second)
                {
                    s.pop();
                }
                if(s.empty()==true)
                {
                    b.push_back(-1);
                }
                else {
                    b.push_back(s.top().first);
                }
            }
            s.push({i,arr[i]});
        }
    }
    void findNSright(vector<int>&arr)
    {
        int n = arr.size();
        stack<pair<int,int>>s;
        for(int i = n-1 ; i >=0 ; i--)
        {
            if(i==n-1){
                a.push_back(n);
            }
            else if(!s.empty() && arr[i]>s.top().second)
            {
                a.push_back(s.top().first);
            }
            else if(!s.empty() and arr[i]<=s.top().second)
            {
                while(!s.empty()&&arr[i]<=s.top().second)
                {
                    s.pop();
                }
                if(s.empty()==true)
                {
                    a.push_back(n);
                }
                else {
                    a.push_back(s.top().first);
                }
                
            }
            s.push({i,arr[i]});
        }
        reverse(a.begin(),a.end());
    }
    int largestRectangleArea(vector<int>& arr) {
        
        findNSright(arr);
        findNSleft(arr);
        int n = arr.size();
        // for(auto it : a)
        // {
        //     cout << it <<" ";
        // }cout<<endl;
        // for(auto it : b){
        //     cout<<it <<" ";
        // }
        int width[n];
        
        int maxi = 0;
        for(int i = 0 ; i < n ; i++)
        {
            width[i]=abs(a[i]-b[i]-1);
            maxi = max(maxi,width[i]*arr[i]);
        }
        
        
        
        
        return maxi;
        
        // int ans = 0;
        // for(int i = 0 ; i < n ; i++)
        // {
        //     int ele = arr[i];
        //     for(int j = i ; j < n ; j++)
        //     {
        //         ele = min(ele,arr[j]);
        //         ans= max(ans,ele*(abs(j-i)+1));
        //     }
        // }
        // return ans;
        
        
    }
};