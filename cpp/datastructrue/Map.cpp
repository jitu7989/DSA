#include <bits/stdc++.h>
using namespace std;

template <typename Key, typename Value, typename Hash = std::hash<Key>>
class UnorderedMapLinearProbing
{
public:
    static const size_t DEFAULT_SIZE = 10;

    size_t size;
    std::pair<Key, Value> *table;
    Hash hasher;

    UnorderedMapLinearProbing(size_t initialSize = DEFAULT_SIZE) : size(initialSize)
    {
        table = new std::pair<Key, Value>[size];
    }

    ~UnorderedMapLinearProbing()
    {
        delete[] table;
    }

    size_t getHash(const Key &key) const
    {
        return hasher(key) % size;
    }

    void insert(const Key &key, const Value &value)
    {
        size_t index = getHash(key);

        while (table[index].first != Key())
        {
            // Linear probing: move to the next index if the current one is occupied
            index = (index + 1) % size;
        }

        table[index] = std::make_pair(key, value);
    }

    bool find(const Key &key, Value &value) const
    {
        size_t index = getHash(key);

        while (table[index].first != Key())
        {
            if (table[index].first == key)
            {
                value = table[index].second;
                return true;
            }

            // Linear probing: move to the next index
            index = (index + 1) % size;
        }

        return false;
    }

    void remove(const Key &key)
    {
        size_t index = getHash(key);

        while (table[index].first != Key())
        {
            if (table[index].first == key)
            {
                // Clear the entry by replacing it with a default-constructed pair
                table[index] = std::make_pair(Key(), Value());
                return;
            }

            // Linear probing: move to the next index
            index = (index + 1) % size;
        }
    }
};

int main()
{
    UnorderedMapLinearProbing<std::string, int> myMap;

    myMap.insert("one", 1);
    myMap.insert("two", 2);
    myMap.insert("two", 3);

    int value;

    if (myMap.find("two", value))
    {
        std::cout << "Value for key 'two': " << value << std::endl;
    }
    else
    {
        std::cout << "Key 'two' not found" << std::endl;
    }

    myMap.remove("two");

    if (myMap.find("two", value))
    {
        std::cout << "Value for key 'two': " << value << std::endl;
    }
    else
    {
        std::cout << "Key 'two' not found after removal" << std::endl;
    }

    return 0;
}
