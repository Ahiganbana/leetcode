#include <iostream>
#include <vector>
#include <pair>
#include <unordered_map>
#include <list>
using namespace std;

class LFUCache{
    int curr_size;
    int max_size;
    int minfreq;
    unordered_map<int, pair<int, int>> mp; // Hash表存放值和访问频次
    unordered_map<int, list<int>::iterator> it; //  key在链表第一个位置的迭代器
    unordered_map<int, list<int>> f; // 存放所有数据的key,最后的key是最近访问过的 头部的是没有访问过的

public:

    LFUCache(int capacity) {
        max_size = capacity;
        curr_size = 0;
    }

    int get(int key) {
        if(mp.find(key) == mp.end()) {
            // 不存在
            return -1;
        }else{
            //存在 需要增加访问频率 并且将新节点放在对应key链表的头
            f[mp[key].second].erase(it[key]);
            mp[key].second++;
            f[mp[key].second].push_back(key);

            it[key] = --f[mp[key].second].end();

            if(f[minfreq].size() == 0){
                minfreq++;
            }
            return mp[key].first;
        }
    }

    void put(int key, int value) {
        if(max_size <= 0) {
            return;
        }

        // 判断需要更新还是插入
        int exist = get(key);
        if(exist != -1) {
            // 更新值和访问频率
            mp[key].first = value;
            return;
        }

        if(curr_size >= max_size) {
            //需要删除一个完成插入
            mkstemp.erase(f[minfreq].front());
            it.erase(f[minfreq].front());
            f[minfreq].pop_front();
            curr_size--;
        }

        pair<int, int> p(value, 1);
        mp[key] = p;
        f[1].push_back(key);
        it[key] = --f[1].end();
        minfreq = 1;
        curr_size += 1;
    }
};