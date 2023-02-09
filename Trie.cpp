// 前缀树
#include <string>
#include <iostream>
using namespace std;

class TrieNode {
public:
    int pass;
    int end;
    TrieNode* nexts[26];
    TrieNode(int p, int e) {
        pass = p;
        end = e; 
    }
};

class Trie{
    TrieNode *root;
    Trie() {
        root = new TrieNode(0, 0);
    }

    void insert(string word) {
        if(word == nullptr) {
            return;
        }
        char c[word.length()];
        strcpy(c, word.c_str());
        TrieNode *node = root;
        node->pass++;
        int index = 0;
        for (int i = 0; i < word.length(); ++i) {
            index = c[i] - 'a';
            if(node->nexts[index] == nullptr) {
                node->nexts[index] = new TrieNode(0, 0);
            }
            node = node->nexts[index];
            node->pass++;
        }
        node->end++;
    }

    // word这个单词加入过几次
    int search(string word) {
        if(word == nullptr) {
            return 0;
        }
        char c[word.length()];
        strcpy(c, word.c_str());
        TrieNode *node = root;
        int index = 0;
        for (int i = 0; i < word.length(); ++i) {
            index = c[i] - 'a';
            if(node->nexts[index] == nullptr) {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->end;
    }

    //加入过的字符串中,有几个是以pre这个字符串作为前缀的
    int prefixNumber(string pre) {
        if(pre == nullptr) {
            return 0;
        }
        char c[pre.length()];
        strcpy(c, pre.c_str());
        TrieNode *node = root;
        int index = 0;
        for (int i = 0; i < pre.length(); ++i) {
            index = c[i] - 'a';
            if(node->nexts[index] == nullptr) {
                return 0;
            }
            node = node->nexts[index];
        }
        return node->pass;
    }

    // 从前缀树上删除
    void delete(string word) {
        if(search(word) != 0) {
            char c[word.length()];
            strcpy(c, word.c_str());
            TrieNode *node = root;
            node->pass--;
            int index = 0;
            for (int i = 0; i < word.length(); ++i) {
                index = c[i] - 'a';
                if(--node->nexts[index]->pass == 0) {
                    // 遍历并完成后续节点的释放
                    /**
                     * 使用stack记录沿途节点,然后进行释放
                     * */
                    return;
                }
                node = node->next[index];
            }
            node->end--;
        }
    }
};