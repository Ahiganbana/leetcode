#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
    vector<vector<int>> edge;
    vector<int> visited;
    bool valid = true;

public:
    //求图的拓扑排序
    //使用图的深度优先遍历
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        /**
         * 1.选取一个节点,并依次查找它的邻接结点
         * 2.直到有一个邻接结点的其余邻接结点全部都访问过,将这个节点入栈
         * 3.如果节点A的临界点B处于正在搜索的状态说明此时图中含有环,没办法找到一个拓扑排序
         * 4.节点全部入栈后,得到的栈中元素反序列,就是图的拓扑排序
         * */
        edge.resize(numCourses);
        visited.resize(numCourses);
        for(const auto& info:prerequisites) {
            //某一个顶点的相邻顶点关系
            edge[info[1]].push_back(info[0]);
        }

        for (int i = 0; i < numCourses && valid; ++i) {
            if(!visited[i]) {
                dfs[i];
            }
        }
        return valid;
    }

    void dfs(int u){
        //正在搜索u节点
        visited[u] = 1;
        for(int v: edge[u]){
            if(visited[v] == 0){
                //该节点没有被访问过,进行深度优先访问
                dfs(v);
                if(!valid) {
                    return;
                }
            }
            else if(visited[v] == 1) {
                //该节点正在被访问,说明此时图中有环,没有拓扑排序
                valid = false;
                return;
            }
        }

        //u节点搜索完毕
        visited[u] = 2;
    }
};

class Solution1 {
public:
    vector<vector<int>> edge;
    vector<int> indeg;
    //使用广度优先遍历
    //此时需要记录每个节点的入度
    bool canFinished(int numCourses, vector<vector<int>>& prerequisites) {
        edge.resize(numCourses);
        indeg.resize(numCourses);
        for(const auto& info:prerequisites) {
            edge[info[1]].push_back(info[0]);
            ++indeg[info[0]];
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if(indeg[i] == 0) {
                q.push(i);
            }
        }

        //需要记录被放入队列中的数的个数
        int visit = 0;
        while(!q.empty()) {
            ++visit;
            int u = q.front();
            q.pop();
            for(int v:edge[u]) {
                --indeg[v];
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
        }

        return visit == numCourses;
    }
}