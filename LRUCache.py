class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.capacity = capacity
        self.cache = collections.OrderedDict()

    # @return an integer
    def get(self, key):
        val = cache[key] if key in self.cache else -1
        if val != -1: 
            del self.cache[key]
            self.cache[key] = val
        return val

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        if key not in self.cache:
            if len(self.cache) == self.capacity:
                self.cache.popitem(last=False)
        else: del self.cache[key]
        self.cache[key] = value