#include <unordered_map>
#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Element {
public:
    // 联盟的编号
    int value;

    // 联盟的人数
    int num;
    Element(int v, int n) {
        value = v;
        num = n;
    }

    bool operator ==(const Element &e1) const {
        return value == e1.value;
    }

    Element& operator =(const Element &e1) {
        value = e1.value;
        num = e1.num;
        return *this;
    }

    Element(const Element &e1) {
        value = e1.value;
        num = e1.num;
    }

    Element(){
        
    }

};


struct hashfunc
{
	size_t operator()(const Element v) const
	{
		return size_t(v.value*14514+v.num*19);
	}	
};


class UnionFindSet {

public :
    // 元素和其包装后的元素的对应表
    unordered_map<int, Element> elementMap;
    // 每个队所属的联盟对应表
    unordered_map<Element, Element, hashfunc> fatherMap;
    // key 某个联盟中的代表元素 value 该联盟的人数
    unordered_map<Element, int, hashfunc> sizeMap;

    // 构造并查集
    UnionFindSet(vector<int> list) {
        for (int i = 0; i < list.size(); ++i)
        {
            Element element(i + 1, list[i]);
            // elementMap.insert(make_pair(i + 1, element));
            // fatherMap.insert(make_pair(element, element));
            // sizeMap.insert(make_pair(element, list[i]));
            elementMap[i + 1] = element;
            fatherMap[element] = element;
            sizeMap[element] = list[i];
        }
    }

    // 判断是否属于一个联盟
    bool isSameSet(int a, int b) {
        if(elementMap.find(a) != elementMap.find(b)) {
            return findHead(elementMap[a]) == findHead(elementMap[b]);
        }
        return false;
    }

    // findHead 调用越频繁 时间复杂度越低
    Element findHead(Element &element) {
        stack<Element> path;
        while( !(element == fatherMap[element])) {
            path.push(element);
            element = fatherMap[element];
        }

        while(!path.empty()) {
            //fatherMap.insert(make_pair(path.top(), element));
            fatherMap[path.top()] = element;
            path.pop();
        }
        return element;
    }

    // a 和 b 联盟
    int unionf(int a, int b) {
        if(elementMap.find(a) != elementMap.end() && elementMap.find(b) != elementMap.end()) {
            Element aF = findHead(elementMap[a]);
            Element bF = findHead(elementMap[b]);
            // 这里是否需要判断两个对象是一个对象需要重载==
            if( !(aF == bF)) {
                Element big = sizeMap[aF] >= sizeMap[bF] ? aF : bF;
                Element small = big == aF ? bF : aF;
                // 将编号大的挂在编号小的编队上
                // fatherMap.insert(big, small);
                fatherMap[big] = small;
                sizeMap[small] = sizeMap[aF] + sizeMap[bF];
                sizeMap.erase(big);
            }
            return (a + b) ^ (abs(aF.num - bF.num));
        }
        return 0;
    }
};

void process(int t, int a, int b, UnionFindSet &ufs) {
    if(t == 1) {
        // 联盟命令 将a 和b 联盟 输出结盟需要的金币数量
        int res = ufs.unionf(a, b);
        cout << res << endl;
    }
    if(t == 2) {
        //查询命令 问a和b是否属于一个联盟
        bool res = ufs.isSameSet(a, b);
        if(res) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}


int main() {
    int n = 0, m = 0;
    cin >> n >> m;
    vector<int> numVec(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> numVec[i];
    }
    UnionFindSet ufs(numVec);
    int t = 0, a = 0, b = 0;
    for (int i = 0; i < m; ++i) {
        cin >> t >> a >> b;
        process(t, a, b, ufs);
    }
    system("pause");
    return 0;
}