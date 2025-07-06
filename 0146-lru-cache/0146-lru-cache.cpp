class LRUCache {
private:
    int capacity;

    // Double-ended queue: stores {key, value}
    list<pair<int, int>> lruList;

    // Maps key -> iterator to corresponding node in list
    unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        // Move accessed node to front (most recently used)
        auto node = cache[key];
        int value = node->second;
        lruList.erase(node);
        lruList.push_front({key, value});
        cache[key] = lruList.begin();

        return value;
    }

    void put(int key, int value) {
        // If key exists, remove old
        if (cache.find(key) != cache.end()) {
            lruList.erase(cache[key]);
        }
        // If over capacity, remove LRU from list and map
        else if (lruList.size() == capacity) {
            auto lru = lruList.back();
            cache.erase(lru.first);
            lruList.pop_back();
        }

        // Insert new node at front
        lruList.push_front({key, value});
        cache[key] = lruList.begin();
    }
};
