// 实现O(1)时间复杂度的插入删除 和返回一个随机的元素
#include <iostream>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename K>
class RandomPool {
    unordered_map<int, K> indexMap;
    unordered_map<K, int> valueMap;
    int size;

    RandomPool() {
        size = 0;
    }

    void insert(K key) {
        if(indexMap.find(key) == indexMap.end()) {
            valueMap[key] = size;
            indexMap[size++] = key;
        }
    }

    void delete(K key) {
        // 为了保证随机返回操作的等概率 每次将要删除的记录移动到最后一个,将最后一个位置的数放在删除后的位置
        if(valueMap.find(key) != valueMap.end()) {
            // 得到要删除的key的索引
            int deleteIndex = valueMap[key];
            int lastIndex = --size;
            K lastKey = indexMap[lastIndex];
            valueMap[lastKey] = deleteIndex;
            indexmap[deleteIndex] = lastKey;
            indexMap.erase(lastIndex);
            valueMap.erase(key);
        }
    }

    K getRandom() {
        if(size == 0) {
            return NULL;
        }
        srand(time(nullptr));
        int randomIndex = (int)(rand() % size);
        return indexMap[randomIndex];
    }


};