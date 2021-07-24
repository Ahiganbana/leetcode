#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

//实现一颗字典树
struct Trie{
    bool isWord;
    Trie *children[26];
    Trie() {
        isWord = false;
        for(auto& child : children) {
            child = nullptr;
        }
    }
};

class WordDictionary {
private:
    Trie *root = nullptr;

public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Trie();
    }
    
    void addWord(string word) {
        auto p = root;
        for(const auto& ch : word) {
            int index = ch - 'a';
            if(!p->children[index]) {
                p->children[index] = new Trie();
            }
            p = p->children[index];
        }
        p->isWord = true;
    }
    
    bool search(string word) {
        auto p = root;
        return match(word, p, 0);
    }

    bool match(string word, Trie* p, int start) {
        if(!p) {
            return false;
        }
        if(start == word.size()) {
            return p->isWord;
        }

        auto &ch = word[start];
        if(ch != '.') {
            int index = ch - 'a';
            if(!p->children[index]) {
                return false;
            }
            p = p->children[index];
            return match(word, p, start + 1);
        }else{
            for (auto ch = 'a'; ch <= 'z'; ch++) {
                int index = ch - 'a';
                if(match(word, p->children[index], start + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};

int main() {
    WordDictionary *obj = new WordDictionary();
    int n = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        obj->addWord(s);
    }
    string str;
    int t = 0;
    while(t != -1) {
        cin >> str >> t;
        bool parm = obj->search(str);
        cout << parm << endl;
    }
    delete obj;
    system("pause");
    return 0;
}

/*
3
bad
dad
mad
pad 1
*/