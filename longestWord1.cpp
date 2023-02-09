#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;


class TrieNode {
public:
    int pass;
    int end;
    TrieNode* next[26];
    TrieNode(int p, int e) {
        pass = p;
        end = e;
        for (int i = 0; i < 26; ++i) {
            next[i] = nullptr;
        }
    }
};

class Trie {
public: 
    TrieNode *root;
    vector<string> words;
    Trie() {
        root = new TrieNode(0, 0);
    }

    void insert(string s) {
        if(s.size() == 0) {
            return;
        }
        TrieNode *node = root;
        node->pass++;
        int index = 0;
        for(int i = 0; i < s.size(); ++i) {
            index = s[i] - 'a';
            if(!node->next[index]) {
                node->next[index] = new TrieNode(0, 0);
            }
            node = node->next[index];
            node->pass++;
        }
        node->end++;
    }

    string dfs() {
        string ans = "";
        stack<TrieNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TrieNode* node = stk.top();
            stk.pop();
            if(node->end > 0 || node == root) {
                if(node != root) {
                    string word = words[node->end - 1];
                    if(word.length() > ans.length() || word.length() == ans.length() && word < ans) {
                        ans = word;
                    }
                }
                for(TrieNode *nei : node->next) {
                    if(nei) {
                        stk.push(nei);
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    string longestWord(vector<string> &words) {
        Trie *tree = new Trie(); 
        for(int i = 0; i < words.size(); ++i) {
            tree->insert(words[i]);
        }
        return tree->dfs();
    }
};


int main() {
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
    Solution solution;
    string result = solution.longestWord(words);
    cout << result << endl;
    system("pause");
    return 0;
}