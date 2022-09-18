class Solution {
public:
    
    // structure for TrieNode
    
    struct TrieNode
    {
        TrieNode* child[26];
        
        int count;
        
        TrieNode()
        {
            count = 0;
            
            for(int i = 0; i < 26; i++)
            {
                child[i] = NULL;
            }
        }
    };
    
    // declare a global root
    
    TrieNode* root = new TrieNode();
    
    // function for insert
    
    void insert(string str)
    {
        int n = str.size();
        
        TrieNode* curr = root;
        
        for(int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            
            // insert a new node
            
            if(curr -> child[idx] == NULL)
            {
                curr -> child[idx] = new TrieNode(); 
            }
            
            // increment the count of prefix
            
            curr -> child[idx] -> count++;
            
            // move curr pointer
          
            curr = curr -> child[idx];
        }
    }
    
    // function for get_sum
    
    int get_sum(string str)
    {
        int n = str.size();
        
        int sum = 0;
        
        TrieNode* curr = root;
        
        for(int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            
            sum += curr -> child[idx] -> count;
            
            curr = curr -> child[idx];
        }
        
        return sum;
    }
    
    vector<int> sumPrefixScores(vector<string>& words) {
        
        int n = words.size();
        
        // insert all the words into trie
        
        for(int i = 0; i < n; i++)
        {
            insert(words[i]);
        }
        
        vector<int> res(n, 0);
        
        // find sum for every word
        
        for(int i = 0; i < n; i++)
        {
            int sum = get_sum(words[i]);
            
            res[i] = sum;
        }
        
        return res;
    }
};