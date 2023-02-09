#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Node {
public :
    string name;
    // map中 节点对应的字符串做key,下一个节点做value
    map<string, Node*> nextMap;


    Node(string n) {
        name = n;
    }
    Node () {

    }

    Node* genreateFolderTree(vector<string> folderPaths) {
        Node *head = new Node("");
        for(string &foldPath : folderPaths) {
            vector<string> paths;
            split(foldPath, paths, '\\');
            Node *cur = head;
            for (int i = 0; i < paths.size(); ++i) {
                // cout << paths[i] << " ";
                if(!cur->nextMap.count(paths[i])) {
                    // cur->nextMap[paths[i]] = new Node(paths[i]);
                    cur->nextMap.insert(make_pair(paths[i], new Node(paths[i])));
                }
                cur = cur->nextMap[paths[i]];
            }
        }
        return head;
    }

    void split(const string& s, vector<string>& tokens, const char& delim = ' ') {
        tokens.clear();
        size_t lastPos = s.find_first_not_of(delim, 0);
        size_t pos = s.find(delim, lastPos);
        while (lastPos != string::npos) {
            tokens.emplace_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delim, pos);
            pos = s.find(delim, lastPos);
        }
    }

    void print(vector<string>& folderPaths) {
        if(folderPaths.size() == 0) {
            return;
        }
        Node *head = genreateFolderTree(folderPaths);

        printProcess(head, 0);
    }

    void printProcess(Node *head, int level) {
        if(level != 0) {
            cout << (get2nSpace(level) + head->name) << endl;
        }
        map<string, Node *>::iterator iter;
        for (iter = head->nextMap.begin(); iter != head->nextMap.end(); iter++) {
            printProcess(iter->second, level + 1);
        }
    }

    string get2nSpace(int n) {
        string res = "";
        for (int i = 1; i < n; ++i) {
            res += " ";
        }
        return res;
    }
};

int main() {
    vector<string> arr = {"b\\cst", "d\\", "a\\d\\e", "a\\b\\c"};
    Node node;
    node.print(arr);
    system("pause");
    return 0;
}