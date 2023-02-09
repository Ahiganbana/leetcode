// 图的数据结构的模板
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Edge {
    int weight;
    Node *from;
    Node *to;
    Edge(int w) : weight(w), from(NULL), to(NULL) {}
};

class Node {
    int value;
    int in; //入度
    int out; // 出度
    vector<Node*> nexts;
    vector<Edge*> edges;
    Node(int v) {
        value = v;
        in = 0;
        out = 0;
    }
};

class Graph{
    unordered_map<int, Node*> nodes;
    unordered_set<Edge*> edges;
};