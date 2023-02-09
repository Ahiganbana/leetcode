#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int preValue = INT_MIN;

bool isBST(TreeNode *head) {
    if(!head) {
        return true;
    }

    bool leftIsBst = isBST(head->left);
    if(!leftIsBst) {
        return false;
    }

    if(head->val <= preValue) {
        // 如果树根上的值小于左孩子的值
        return false;
    }else {
        preValue = head->val;
    }
    return isBST(head->right);
}

// 每个节点希望从子树上获得的信息 : 是否是搜索树 树上的最大值 树上的最小值
struct ReturnData {
    bool isBST;
    int minValue;
    int maxValue;
    ReturnData(bool ib, int minv. int maxv) : isBST(ib), minValue(minv), maxValue(maxv){}
};

ReturnData* process(TreeNode *tree) {
    if(!tree) {
        return nullptr;
    }
    ReturnData *leftData = process(tree->left);
    ReturnData *rightData = process(tree->right);

    int minValue = tree->val;
    int maxValue = tree->val;

    if (leftData) {
        minValue = min(leftData->minValue, minValue);
        maxValue = max(leftData->maxValue, maxValue);
    }

    if(rightData) {
        minValue = min(rightData->minValue, minValue);
        maxValue = max(rightData->maxValue, maxValue);
    }

    bool isBST = true;
    if(leftData && (!leftData->isBST || leftData->maxValue >= tree->val)) {
        isBST = false;
    }
    if(rightData &&(!rightData->isBST || rightData->minValue <=  tree->val)) {
        isBST = false;
    }
    ReturnData *finalReturn = new ReturnData(isBST, maxValue, minValue);
    return finalReturn;
}

bool isBST(TreeNode* tree) {
    return process(tree)->isBST;
}