#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    string str;
    int times;
    Node (string s, int t) {
        str = s;
        times = t;
    }
};

class TopKRecord {
public:
    vector<Node*> heap;
    // 堆的大小
    int index;
    unordered_map<string, Node*> strNodeMap;
    unordered_map<Node*, int> nodeIndexMap;

    TopKRecord(int size) {
        heap.resize(size);
        index = 0;
    }

    ~TopKRecord() {
        for (int i = 0; i < heap.size(); ++i) {
            delete heap[i];
        }
    }

    void add(string str) {
        Node *curNode = nullptr;
        int preIndex = -1;
        if(!strNodeMap.count(str)) {
            curNode = new Node(str, 1);
            strNodeMap.insert(make_pair(str, curNode));
            nodeIndexMap.insert(make_pair(curNode, -1));
        }else {
            curNode = strNodeMap[str];
            curNode->times++;
            preIndex = nodeIndexMap[curNode];
        }
        if(preIndex == -1) {
            if(index == heap.size()) {
                if(heap[0]->times < curNode->times) {
                    nodeIndexMap.insert(make_pair(heap[0], -1));
                    nodeIndexMap.insert(make_pair(curNode, 0));
                    heap[0] = curNode;
                    heapify(heap, 0, index);
                }
            }else {
                // nodeIndexMap.insert(make_pair(curNode, index));
                nodeIndexMap[curNode] = index;
                heap[index] = curNode;
                heapInsert(heap, index++);
            }
        }else {
            heapify(heap, preIndex, index);
        }
    }

    void heapify(vector<Node*> &arr, int index, int heapSize) {
        int leftChild = index * 2 + 1;
        while(leftChild < heapSize) {
            // 从父亲和两个孩子三者之间选择最小的
            int largest = leftChild + 1 < heapSize && arr[leftChild + 1]->times < arr[leftChild]->times ? leftChild + 1 : leftChild;
            largest = arr[largest]->times < arr[index]->times ? largest : index;

            if(largest == index) {
                break;
            }
            swap(largest, index);
            index = largest;
            leftChild = index * 2 + 1;
        }
    }

    void heapInsert(vector<Node*> & arr, int index) {
        while(arr[index]->times < arr[(index - 1) / 2]->times) {
            swap(index, (index - 1) / 2);
            index = (index - 1) / 2;
        }
    }

    void swap(int index1, int index2) {
        nodeIndexMap.insert(make_pair(heap[index1], index2));
        nodeIndexMap.insert(make_pair(heap[index2], index1));
        Node *tmp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = tmp;
    }

    void printTopK() {
        for (int i = 0; i < heap.size(); ++i) {
            cout << heap[i]->str << " ";
        }
    }
};

int main() {
    TopKRecord t(3);
    t.add("a");
    t.add("b");
    t.add("b");
    t.add("c");
    t.add("c");
    t.add("c");
    t.add("c");
    t.add("d");
    t.add("d");
    t.add("d");
    t.printTopK();
    cout << "succ" << endl;
    system("pause");
    return 0;
}