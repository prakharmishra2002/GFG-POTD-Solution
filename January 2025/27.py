class LRUCache:
      
    # Constructor for initializing the cache capacity with the given value.
    def __init__(self, cap):
        self.cache = {}
        self.capacity = cap
        self.order = []
        
    # Function to return value corresponding to the key.
    def get(self, key):
        if key in self.cache:
            self.order.remove(key)
            self.order.append(key)
            return self.cache[key]
        else:
            return -1
        
    # Function for storing key-value pair.
    def put(self, key, value):
        if key in self.cache:
            self.order.remove(key)
        elif len(self.cache) >= self.capacity:
            oldest = self.order.pop(0)
            del self.cache[oldest]
        self.cache[key] = value
        self.order.append(key)
