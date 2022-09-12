class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin() , tokens.end());
        int r = tokens.size()-1;
        int score = 0;
        int maxi = 0;
        for(int i = 0 ; i < tokens.size() ;)
        {
            if(power>=tokens[i])
            {
                score++;
                power-=tokens[i++];
            }
            else
            {
                if(score>=1 && r>=0)
                {
                    score--;
                    power+=tokens[r--];
                }
                else break;
                
            }
            maxi = max(maxi , score);
        }
        return maxi;
    }
};