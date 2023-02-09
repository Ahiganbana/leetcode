struct TreeNode {
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

int maxValue(TreeNode * root) {
    if(!root->left && !root->right) {
        return root->val;
    }
    int maxv = INT_MIN;
    if(root->left) {
        next = process(root->left);
    }
    if(root->right) {
        next = max(next, process(root->right));
    }
    return next + root->val;
}