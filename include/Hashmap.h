#ifndef Hashmap_H
#define Hashmap_H

#include <vector>

template <typename Key, typename Value>
class Hashmap {
  private:
    std::size_t getBucketIndex(const Key &key) {
        std::size_t key_hash = std::hash<Key>{}(key);
        return key_hash % 10;
    }

    struct Pair {
        Key key;
        Value value;
    };

    std::vector<std::vector<Pair>> buckets = {};

  public:
    Hashmap() {
        buckets.resize(10);
    }

    void add(Key key, Value value) {
        Pair pair;
        pair.key = key;
        pair.value = value;

        buckets.at(getBucketIndex((key))).push_back(pair);
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
