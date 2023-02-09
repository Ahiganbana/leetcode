#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

template <typename V>
class Element {
public:
    V value;
    Element(V v) {
        value = v;
    }
};

template <typename V>
class UnionFindSet {
    // 元素和其包装后的元素的对应表
    unordered_map < V, Element<V>> elementMap;
    // 每个元素和其父亲的对应表
    unordered_map<Element<V>, Element<V>> fatherMap;
    // key 某个集合的代表元素 value 是该集合的大小
    unordered_map<Element<V>, int> sizeMap;

    UnionFindSet(vector<V> list) {
        for(V value : list) {
            Element<V> element = new Element<V>(value);
            elementMap.insert(value, element);
            fatherMap.insert(element, element);
            sizeMap.insert(element, 1);
        }
    }

    bool isSameSet(V a, V b) {
        if(elementMap.find(a) != elementMap.find(b)) {
            return findHead(elementMap[a] == findHead(elementMap[b]));
        }
        return false;
    }

    // findHead 调用越频繁 时间复杂度越低
    Element<V> findHead(Element<V> element) {
        stack<Element<V>> path;
        while(element != fatherMap[element]) {
            path.push(element);
            element = fatherMap[element];
        }

        while(!path.empty()) {
            fatherMap.insert(path.top(), element);
            path.pop();
        }
        return element;
    }

    void unionf(V a, V b) {
        if(elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end()) {
            Element<V> aF = findHead(elementMap[a]);
            Element<V> bF = findHead(elementMap[b]);
            if(aF != bF) {
                Element<V> big = sizeMap[aF] >= sizeMap[bF] ? aF : bF;
                Element<V> small = big == aF ? bF : aF;
                fatherMap.insert(samll, big);
                sizeMap[big] = sizeMap[aF] + sizeMap[bF];
                sizeMap.erase(small);
            }
        }
    }
};