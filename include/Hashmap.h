#ifndef Hashmap_H
#define Hashmap_H

#include <vector>

/// @brief A simple hashmap implementation
/// @tparam Key
/// @tparam Value
template <typename Key, typename Value>
class Hashmap {
    struct Pair {
        Key key;
        Value value;
    };

    std::vector<Pair> pairs;

  public:
    /// @brief Add a key-value pair to the hashmap
    /// @tparam K
    /// @tparam V
    /// @param key
    /// @param value
    template <typename K, typename V>
    void add(K key, V value) {
        Pair pair;
        pair.key = key;
        pair.value = value;

        pairs.push_back(pair);
    }

    /// @brief Get the value associated with a key
    /// @tparam K
    /// @param key
    /// @return Value
    template <typename K>
    Value get(K key) {
        for (auto pair : pairs) {
            if (pair.key == key) {
                return pair.value;
            }
        }

        return Value();
    }

    /// @brief Remove a key-value pair
    /// @tparam K
    /// @param key
    template <typename K>
    void remove(K key) {
        for (int i = 0; i < pairs.size(); i++) {
            if (pairs[i].key == key) {
                pairs.erase(pairs.begin() + i);
                break;
            }
        }
    }
};

#endif