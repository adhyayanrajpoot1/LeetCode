class TrieNode{
    public:
    TrieNode*arr[26];
    bool edge;
    TrieNode()
    {
        for(int i = 0 ; i < 26 ; i++)
        {
            arr[i] = NULL;
        }
        edge = false;
    }
};

class Trie {
public:
    TrieNode*root = new TrieNode();
    Trie() {
        
    }
    
    void insert(string word) {
        TrieNode *node=root;
        for(int i = 0 ; i < word.size() ; i++)
        {
            int index = word[i]-'a';
            if(node->arr[index]==NULL)node->arr[index] = new TrieNode();
            node = node->arr[index];
        }
        node->edge = true;
    }
    
    bool search(string word) {
        TrieNode*node = root;
        for(int i = 0 ; i < word.size() ; i++)
        {
            int index = word[i]-'a';
            if(node->arr[index]==NULL)return false;
            node=node->arr[index];
        }
        return node->edge;
    }
    
    bool startsWith(string prefix) {
        TrieNode*node = root;
        for(int i = 0 ; i < prefix.size() ; i++)
        {
            int index = prefix[i]-'a';
            if(node->arr[index]==NULL)return false;
            node=node->arr[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */