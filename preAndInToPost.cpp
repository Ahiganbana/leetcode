// 根据前序和中序遍历的数组确定后序遍历的数组
#include <iostream>
#include <vector>
using namespace std;

void process(vector<int> pre, vector<int> in, vector<int> post,
            int prei, int prej,
            int ini, int inj,
            int posti, int postj) {
    if(prei > prej) {
        return;
    }
    if(prei == prej) {
        post[posti] = pre[prei];
    }

    //先序遍历的第一个节点是后序遍历的最后一个节点
    post[postj] = pre[prei];
    int find = ini;
    for (; find <= inj; ++find) {
        // 在中序遍历数组中找到头节点
        if(in[find] == pre[prei]) {
            break;
        }
    }
    // 左子树
    process(pre, in, post, prei + 1, prei + find - ini, ini, find - 1, posti, posti + find - ini);
    // 右子树
    process(pre, in, post, prei + find - ini + 1, prej, find + 1, inj, posti + find - ini, postj);
}