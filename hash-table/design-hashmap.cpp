// class MyHashMap {

//     vector<int> mp;
    
// public:
//     MyHashMap() {
//         mp.resize(1000001, -1);
//     }
    
//     void put(int key, int value) {
        
//         mp[key] = value;
//     }
    
//     int get(int key) {
        
        
//         return mp[key];
//     }
    
//     void remove(int key) {
        
//         mp[key] = -1;
//     }
// };

// /**
//  * Your MyHashMap object will be instantiated and called as such:
//  * MyHashMap* obj = new MyHashMap();
//  * obj->put(key,value);
//  * int param_2 = obj->get(key);
//  * obj->remove(key);
//  */

class MyHashMap {
    vector<int> mp;

public:
    MyHashMap() {}

    void put(int key, int value) {
        if (key >= (int)mp.size())
            mp.resize(key + 1, -1);  // +1 ensures valid index
        mp[key] = value;
    }

    int get(int key) {
        if (key >= (int)mp.size())
            return -1;
        return mp[key];
    }

    void remove(int key) {
        if (key < (int)mp.size())
            mp[key] = -1;
    }
};
