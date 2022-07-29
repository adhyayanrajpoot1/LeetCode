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
//     public:
//     int key;
//     int value;
//     Node(int key,int value){
//         this->key = key;
//         this->value = value;
//     }
// };
​
// class LRUCache {
// public:
//     int maxSize;
//     list<Node>l;
//     unordered_map<int,list<Node>::iterator>m;
//     LRUCache(int capacity) {
//         this->maxSize = capacity;
//     }
//     int get(int key) {
//         if(m.count(key)!=0)
//         {
//             auto it = m[key];
//             int value = it->value;
//             l.push_front(*it);
//             l.erase(it);
//             m[key] = l.begin();
//             return value;
//         }
//         return -1;
//     }
//     void put(int key, int value) {
//         if(m.count(key)!=0)
//         {
//             auto it = m[key];
//             it->value = value;