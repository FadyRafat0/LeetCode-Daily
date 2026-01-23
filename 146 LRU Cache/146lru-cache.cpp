class LRUCache {
public:
    int const SIZE = 1e4 + 5, MAX_TIME = 2e5 + 5;
    int cur_time, last_time;
    int max_cap, cur_cap;
    vector<int> val, time, used, last_used_timer;
    LRUCache(int capacity) {
        val.resize(SIZE);
        time.resize(SIZE);
        used.resize(SIZE);

        last_used_timer.resize(MAX_TIME, -1);

        cur_time = last_time = 1;
        cur_cap = 0;
        max_cap = capacity;
    }
    
    int get(int key) {
        if (!used[key]) return -1;  

        last_used_timer[time[key]] = -1;
        time[key] = cur_time++;
        last_used_timer[time[key]] = key;

        return val[key];
    }
    
    void put(int key, int value) {
        if (!used[key]) {
            used[key] = 1;
            ++cur_cap;
        }
        val[key] = value;
        last_used_timer[time[key]] = -1;
        time[key] = cur_time++;
        last_used_timer[time[key]] = key;        
        
        if (cur_cap > max_cap) {
            while (last_used_timer[last_time] == -1) ++last_time;

            int key = last_used_timer[last_time];
            val[key] = used[key] = 0;
            last_used_timer[last_time] = -1;
            ++last_time;
            --cur_cap;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */