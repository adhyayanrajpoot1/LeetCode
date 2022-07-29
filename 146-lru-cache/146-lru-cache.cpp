class Node{
    public:
    int key;
    int value;
    Node(int key , int value)
    {
        this->key = key;
        this->value = value;
    }
};
class LRUCache {
public:
    list<Node>l;
    unordered_map<int,list<Node> :: iterator>m;
    int size;
    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        if(m.count(key)!=0){
            auto it = m[key];
            int num = it->value;
            Node n(it->key,it->value);
            l.erase(it);
            l.push_front(n);
            
            m[key]=l.begin();
            return num;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key)!=0){
            auto it = m[key];
            it->value = value;
            Node n(it->key,it->value);
            l.erase(it);
            l.push_front(n);
            m[key]=l.begin();
            return;
        }
        else {
            if(l.size()==size)
            {
                Node last = l.back();
                m.erase(last.key);
                l.pop_back();
            }
            Node n(key,value);
            l.push_front(n);
            m[key]=l.begin();
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */