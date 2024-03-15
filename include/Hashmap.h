#ifndef Hashmap_H
#define Hashmap_H

#include <array>
#include <functional>
#include <vector>

template <typename Key, typename Value>
class Hashmap {
    std::size_t getBucketIndex(const Key &key) {
        std::hash<Key> hashFunction;
        std::size_t hashCode = hashFunction(key);
        return hashCode % 10;
    }

    struct Pair {
        Key key;
        Value value;
    };

    std::array<std::vector<Pair>, 11> buckets = {};

  public:
    void add(Key key, Value value) {
        Pair pair;
        pair.key = key;
        pair.value = value;

        buckets[getBucketIndex(key)].push_back(pair);
    }

    Value get(Key key) {
        for (const Pair &pair : buckets[getBucketIndex(key)]) {
            if (pair.key == key) {
                return pair.value;
            }
        }

        return Value();
    }

    void remove(const Key &key) {
        std::vector<Pair> &bucket = buckets[getBucketIndex(key)];

        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (it->key == key) {
                it = bucket.erase(it);
                break;
            }
        }
    }
};

#endif
