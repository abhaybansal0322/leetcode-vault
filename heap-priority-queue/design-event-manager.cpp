class EventManager {

    struct cmp {
        bool operator()(pair<int,int> a, pair<int,int> b) {
            if(a.second == b.second) return a.first > b.first;
            return a.second < b.second;
        }
    };

    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
    unordered_map<int,int> mp;
public:
    EventManager(vector<vector<int>>& events) {
        
        for(int i=0;i<events.size();i++) {

            mp[events[i][0]] = events[i][1];
            pq.push({events[i][0],events[i][1]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        
        mp[eventId] = newPriority;
        pq.push({eventId , newPriority});
    }
    
    int pollHighest() {
        while(!pq.empty()) {

            auto [id,val] = pq.top();

            if(mp[id] != val) {

                pq.pop();
                continue;
            }

            mp.erase(id);
            pq.pop();
            return id;
        }

        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */