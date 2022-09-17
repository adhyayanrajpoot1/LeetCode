static const auto fastIO = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        
        /*
        /// O(n^2) TLE
        vector<vector<int>> res;
        
        for(int g=0;g<words.size();g++){
            
            for(int h=0;h<words.size();h++){
                
                if( g == h ) continue;
                
                if( words[g].empty() || words[h].empty() ){
                    
                    string* ptr = words[g].empty() ? &words[h] : &words[g];
                    
                    int i = 0, j = ptr->size()-1;
                    bool match = true;
                    while( i < j ){
                        if( (*ptr)[i] != (*ptr)[j] ){
                            match = false;
                            break;
                        }
                        i++;
                        j--;
                    }
                    if( match ){
                        res.push_back( { g , h } );
                    }
                    continue;
                }
                
                // cout<<":::"<<g<<"."<<h<<endl;
                // cout<<":::compare:"<<words[g]<<" with "<<words[h]<<endl;
                
                bool match = true;
                string* s1 = &words[g], *s2 = &words[h];
                int i = 0, j = s2->size()-1;
                while( true ){
                    
                    // cout<<"compare:"<<s1<<"."<<s2<<" : "<<i<<" . "<<j<<endl;
                    
                    if( (*s1)[i] != (*s2)[j] ){
                        match = false;
                        break;
                    }
                    
                    i++;
                    j--;
                    
                    if( i == s1->size() ){
                        i = 0;
                        s1 = &words[h];
                    }
                    if( j < 0 ){
                        s2 = &words[g];
                        j = words[g].size()-1;
                    }
                    
                    if( (s1 == s2 && i >= j) || (words[g].size() == words[h].size() && s1 == &words[h]) ){
                        break;
                    }
                }
                
                if( match ){
                    // cout<<"match"<<endl;
                    res.push_back( { g , h } );
                }
            }
            
        }
        return res;
        */
        
        
        /*
        /// trie
        class node{
            public:
            node** arr;
            vector<int> idx;
            int w_idx;
            node(){
                arr = new node*[ 26 ];
                for(int t=0;t<26;t++) arr[t] = nullptr;
                idx = {};
                w_idx = -1;
            }
        };
        
        node* root = new node();
                
        auto check = [&](int w_idx,int from,int to) -> bool {
            int i = from, j = to;
            while( i < j ){
                if( words[w_idx][i] != words[w_idx][j] ){
                    return false;
                }
                i++;
                j--;
            }
            return true;
        };
        
        for(int g=0;g<words.size();g++){
            node* curr = root;
            for(int h=0;h<words[g].size();h++){
                if( !curr->arr[ words[g][h]-'a' ] ){
                    curr->arr[ words[g][h] - 'a' ] = new node();
                }
                curr = curr->arr[ words[g][h] - 'a' ];
                
                if( (h+1 <= words[g].size()-1) && check( g , h+1 , words[g].size()-1 ) ){
                    // cout<<"at:"<<words[g].substr(0,h+1)<<" rem is pal:"<<words[g].substr(h+1)<<endl;
                    curr->idx.push_back( g );
                }
            }
            curr->idx.push_back( g );
            curr->w_idx = g;
        }
        
        vector<vector<int>> res;
        for(int g=0;g<words.size();g++){
            
            if( (root->w_idx != -1) && (root->w_idx != g) && check( g , 0 , words[g].size()-1 ) ){
                // cout<<"here"<<endl;
                res.push_back( { root->w_idx , g } );
                res.push_back( { g , root->w_idx } );
            }
            
            node* curr = root;
            
            int h;
            for(h=words[g].size()-1;h>=0;h--){
                if( !curr->arr[ words[g][h]-'a' ] ) break;
                curr = curr->arr[ words[g][h] - 'a' ];
                if( curr->w_idx != -1 && h-1 >= 0 && check( g , 0 , h-1 ) ){
                    // cout<<"we have for word:"<<words[g]<<" palindrom part:"<<words[g].substr(0,h)<<endl;
                    // cout<<"here2"<<endl;
                    res.push_back( { curr->w_idx , g } );
                }
            }
            
            if( h < 0 ){
                for(int r=0;r<curr->idx.size();r++){
                    if( curr->idx[r] != g )
                        res.push_back( { curr->idx[r] , g } );
                }
            }
            
        }
        return res;
        */
        
        
        //// third-sol
        map<int,unordered_map<string,int>> memo;
        for(int g=0;g<words.size();g++){
            string str = string( words[g].rbegin() , words[g].rend() );
            memo[ words[g].size() ][ str ] = g;
        }
        
        auto check = [&](string& str,int i,int j) -> bool {
            while( i < j ){
                if( str[i] != str[j] ) break;
                i++;
                j--;
            }
            return i >= j;
        };
        
        vector<vector<int>> res;
        for(int g=0;g<words.size();g++){
            
            string& str = words[g];
            
            for(auto& p : memo){
                if( p.first > str.size() ) break;
                
                if( p.first == str.size() ){
                    
                    if( p.second.count(str) && p.second[str] != g ){
                        res.push_back( { g , p.second[str] } );
                    }
                    
                    continue;
                }
                
                if( check( str , 0 , words[g].size()-1 - p.first ) && p.second.count( words[g].substr(words[g].size()-p.first) ) ){
                    // cout<<"first"<<endl;
                    res.push_back( { p.second[ words[g].substr( words[g].size()-p.first ) ] , g } );
                }
                
                if( check( str , words[g].size() - ( words[g].size() - p.first ) , words[g].size()-1 ) && p.second.count( words[g].substr( 0 , p.first ) ) ){
                    // cout<<"second"<<endl;
                    res.push_back( { g , p.second[ words[g].substr( 0 , p.first ) ] } );
                }
            }
        }
        return res;
        
    }
};

/*

["a","b","c","ab","ac","aa"]
["abcd","dcba","lls","s","sssll"]
["a",""]
["a","b","c","ab","ac","aa"]
["abcd","dcba","lls","s","sssll"]

*/