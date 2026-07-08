class LRUCache {
public:
    list<int> dll;
    unordered_map<int,pair<list<int>::iterator,int>> mp; // key-> address,value
    int n;

    void makeRecentlyUsed(int key)
    {
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first = dll.begin(); 
    }

    LRUCache(int capacity) {
        n = capacity;   
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end())
        {
            return -1;
        }

        makeRecentlyUsed(key);
        return mp[key].second;
        
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            mp[key].second = value;
            makeRecentlyUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key].first = dll.begin();
            mp[key].second = value;
            n--;
        }

        if(n < 0)
        {
            int rem = dll.back();
            mp.erase(rem);
            dll.pop_back();
            n++;
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */