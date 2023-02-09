// 模拟折纸的过程
/**转化为二叉树 每次对折会在原来折痕的上下两层分别形成一条凹折痕和 一条凸折痕
 * */
#include <iostream>
using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

 // i 表示当前是第几层 N表示最多到第几层 down指示了当前的折痕是否是凹折痕
 void printProcess(int i, int N, bool down) {
     if(i > N) {
         return;
     }
     printProcess(i + 1, N, true); // 左子树的根节点都是凹
     cout << (down ? "凹" : "凸");
     printProcess(i + 1, N, false); // 右子树的根节点都是凸
 }

 void printAllFolds(int N) {
     printProcess(1, N, true);
 }