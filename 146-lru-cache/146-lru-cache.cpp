class LRUCache {
public:
    unordered_map< int , pair< list<int> :: iterator , int>> mp; 
    int cap;
    list<int> l;
    
   
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    // in doubly linked list , for erase put the node , not the value
    
    void put_at_first(int key)
    {
        l.erase(mp[key].first);
        
        l.push_front(key);
        mp[key].first=l.begin();
    }
   
    
    int get(int key) {
       if(mp.find(key)==mp.end())
       {
           return -1;
       }
        
        put_at_first(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        
        if(mp.find(key)!=mp.end())
        {
            l.erase(mp[key].first);
            l.push_front(key);
            mp[key]={l.begin() , value};
            
        }
        else
        {
            if(mp.size()==cap)
            {
                auto val=l.back();
                
                l.pop_back();
                mp.erase(val);
                l.push_front(key);
                mp[key]={l.begin() , value};
            }
            else
            {
                l.push_front(key);
                mp[key]={l.begin() , value};
            }
        }
      
     
    }
};
// class Node{
//     public:
//     int key;
//     int value;
//     Node(int key,int value){
//         this->key = key;
//         this->value = value;
//     }
// };

// class LRUCache {
// public:
//     int maxSize;
//     list<Node>l;
//     unordered_map<int,list<Node>::iterator>m;
//     LRUCache(int capacity) {
//         this->maxSize = capacity;
//     }
    
//     int get(int key) {
//         if(m.count(key)!=0)
//         {
//             auto it = m[key];
//             int value = it->value;
//             l.push_front(*it);
//             l.erase(it);
//             m[key] = l.begin();
//             return value;
//         }
//         return -1;
//     }
    
//     void put(int key, int value) {
//         if(m.count(key)!=0)
//         {
//             auto it = m[key];
//             it->value = value;
//         }
//         else{
//             if(l.size()==maxSize)
//             {
//                 Node last = l.back();
//                 cout<<last.key<<" "<<last.value<<endl;
//                 m.erase(last.key);
//                 l.pop_back();
//             }
//             Node n(key,value);
//             l.push_front(n);
//             m[key]=l.begin();
//         }
//     }
// };

// /**
//  * Your LRUCache object will be instantiated and called as such:
//  * LRUCache* obj = new LRUCache(capacity);
//  * int param_1 = obj->get(key);
//  * obj->put(key,value);
//  */