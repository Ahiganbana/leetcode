#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> paths;
        string path = "";
        buildPath(root, path, paths);
        return paths;
    }

    void buildPath(TreeNode* root, string path, vector<string> &paths) {
        if(root) {
            path += to_string(root->val);
            if((!root->left) && (!root->right)) {
                paths.push_back(path);
            }else{
                path += "->";
                buildPath(root->left, path, paths);
                buildPath(root->right, path, paths);
            }
        }
    }
};
int main() {
    string a = "123";
    string b = "abc";
    b += a;
    string c = "";
    c += b;
    cout << c << endl;
    system("pause");
    return 0;
}