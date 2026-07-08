class Router {
    
    int memory;
    queue<tuple<int,int,int>> que;
    unordered_set<string> checkPacket;
    unordered_map<int,vector<int>> destTimes;

    string getKey(int source, int destination, int timestamp) {
    return to_string(source) + "," + to_string(destination) + "," + to_string(timestamp);
    }
    
public:
    Router(int memoryLimit) {
        memory = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        string Key = getKey(source,destination,timestamp);
        if(checkPacket.count(Key))
        {
            return false;
        }

        que.push(make_tuple(source,destination,timestamp));
        checkPacket.insert(Key);
        destTimes[destination].push_back(timestamp);

        if(que.size() > memory)
        {
            auto oldest = que.front();
            que.pop();

            string oldestkey = getKey(get<0>(oldest), get<1>(oldest), get<2>(oldest));
            checkPacket.erase(oldestkey);

            int oldDest = get<1>(oldest);
            auto& timestamps = destTimes[oldDest];
            timestamps.erase(timestamps.begin());
            if (timestamps.empty()) {
                destTimes.erase(oldDest);
            }
            
        }

        return true;
    }
    
    vector<int> forwardPacket() {
        if(que.empty())
            return {};

        auto oldest = que.front();
        que.pop();

        string oldestkey = getKey(get<0>(oldest), get<1>(oldest), get<2>(oldest));
        checkPacket.erase(oldestkey);

        int oldDest = get<1>(oldest);
        auto& timestamps = destTimes[oldDest];
        timestamps.erase(timestamps.begin());
        if (timestamps.empty()) {
            destTimes.erase(oldDest);
        }

        return {get<0>(oldest), get<1>(oldest), get<2>(oldest)};

    }
    
    int getCount(int destination, int startTime, int endTime) {
        auto it = destTimes.find(destination);
        if(it == destTimes.end())
            return 0;

        vector<int>& timestamps = it->second;
        auto Lower = lower_bound(timestamps.begin(),timestamps.end(),startTime);
        auto Upper = upper_bound(timestamps.begin(),timestamps.end(),endTime);

        return distance(Lower,Upper);
        
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */