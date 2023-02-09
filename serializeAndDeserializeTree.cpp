#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) {
            return "#_";
        }
        string res = to_string(root->val) + "_";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        split(data, tokens, '_');
        queue<string> q;
        for (int i = 0; i < tokens.size(); ++i) {
            q.push(tokens[i]);
        }
        return preOrder(q);
    }

    TreeNode *preOrder(queue<string> &q) {
        string value = q.front();
        q.pop();
        if(value == "#") {
            return nullptr;
        }
        TreeNode *head = new TreeNode(stoi(value));
        head->left = preOrder(q);
        head->right = preOrder(q);
        return head;
    }

    void split(const string &s, vector<string> &tokens, const char &delim = ' ') {
        tokens.clear();
        size_t lastPos = s.find_first_not_of(delim, 0);
        size_t pos = s.find(delim, lastPos);
        while (lastPos != string::npos) {
            tokens.emplace_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delim, pos);
            pos = s.find(delim, lastPos);
        }
    }
};
