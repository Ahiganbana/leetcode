// 找到二叉搜索树的最低公共祖先
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

template<class T> class binary_tree
{
    typedef binary_tree_node<T> node;
public:
    binary_tree(T* a, size_t n, const T&invalid)
    {
        size_t index = 0;
        _root = _create_tree(a, n, invalid, index);
    }
    TreeNode*copy_tree(TreeNode* root)
    {
        if (root == NULL)
        { 
            return NULL;
        }
        TreeNode* new_root = new TreeNode(root->_data);
        new_root->_left = copy_tree(root->_left);
        new_root->_right = copy_tree(root->_right);

        return new_root;
    }
    binary_tree(const binary_tree<T>& t)
    {
        _root = copy_tree(t._root);
    }
    binary_tree<T>& operator=(binary_tree<T> t)
    {
        swap(_root, t._root);
        return *this;
    }
    ~binary_tree()
    {
        destory(_root);
        _root = NULL;
    }
    void destory(TreeNode* root)
    {
        if (root == NULL)
            return;
        destory(root->_left);
        destory(root->_right);

        delete root;
    }

    //创建一棵二叉树
    TreeNode* _create_tree(T*a, size_t n, const T& invalid, size_t& index)
    {
        TreeNode* root = NULL;
        if (a[index] != invalid)
        {
            root = new TreeNode(a[index]);
            root->_left = _create_tree(a, n, invalid, ++index);
            root->_right = _create_tree(a, n, invalid, ++index);
        }
        return root;
    }
};

class Solution {
public:

    // 方法一 : 使用Map记录所有节点的父节点信息,并且记录从给定节点开始向上的路径
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode *, TreeNode *> fatherMap;
        fatherMap.insert(make_pair(root, root));
        process(root, fatherMap);
        unordered_set<TreeNode *> set1;

        TreeNode *cur = p;
        while(cur != fatherMap[cur]) {
            set1.insert(cur);
            cur = fatherMap[cur];
        }
        set1.insert(root);

        TreeNode *curr = q;
        TreeNode *res = root;
        // 如果该节点就在上一个节点向上的路上直接返回
        if(set1.find(curr) != set1.end()) {
            return curr;
        }
        // 在p向上的路径中找q 如果q的父节点在set1中
        while(curr != fatherMap[curr]) {
            if(set1.find(fatherMap[curr]) != set1.end()) {
                res = fatherMap[curr];
                break;
            }
            curr = fatherMap[curr];
        }
        return res;
    }

    void process(TreeNode *tree, unordered_map<TreeNode*, TreeNode*> &mp) {
        if(!tree) {
            return;
        }
        mp.insert(make_pair(tree->left, tree));
        mp.insert(make_pair(tree->right, tree));
        process(tree->left, mp);
        process(tree->right, mp);
    }

    //方法二: 递归的方式求解
    TreeNode *lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == q || root == p) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        // 分两种情况
        //1. p q 互相为公共祖先
        //2. p q 汇聚到一个公共节点
        if(left && right) { // 情况2
            return root;
        }
        return left ? left : right; 
    }
};
