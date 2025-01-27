#include <unordered_map>
#include <list>

class LRUCache {
  private:
    int capacity;
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;
    std::list<int> order;
    
  public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) : capacity(cap) {}

    // Function to return value corresponding to the key.
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
            order.push_front(key);
            cache[key].second = order.begin();
            return cache[key].first;
        } else {
            return -1;
        }
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            order.erase(cache[key].second);
        } else if (cache.size() >= capacity) {
            int oldest = order.back();
            order.pop_back();
            cache.erase(oldest);
        }
        order.push_front(key);
        cache[key] = {value, order.begin()};
    }
};
