class Solution {
public:
    string countAndSay(int n) {
        string res = "1";
        for(int i=2; i<=n; i++){
            string temp;
            res.push_back('#');
            int count=1;
            for(int j=1; j<res.length(); j++){
                if(res[j-1]!=res[j]){
                    temp+= to_string(count);
                    count=1;
                    temp+= res[j-1];
                }else{
                    count++;
                }
            }
            res = temp;
        }
        return res;
    }
};