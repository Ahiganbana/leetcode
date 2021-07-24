#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param heights int整型vector 
     * @return int整型vector
     */
    vector<int> findBuilding(vector<int>& heights) {
        // write code here
        int n = heights.size();
        //存放结果的数组,保证可以看到自己所见的楼初始化为1
        vector<int> result(n, 1);
        //向左看时的楼
        vector<int> left;
        //向右看时的楼
        vector<int> right;
        for(int i = 0; i < n - 1; ++i){
            while(!left.empty() && heights[i] >= left.back()){
                left.pop_back();
            }
            left.push_back(heights[i]);
            result[i + 1] += left.size();
        }
        
        //向左看时的楼
        for(int i = n - 1; i>= 0; --i) {
            while(!right.empty() && heights[i] >= right.back()){
                right.pop_back();
            }
            right.push_back(heights[i]);
            result[i - 1] += right.size();
        }
        return result;
    }
};

int main() {
    int n = 0;
    cin >> n;
    vector<int> heights(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }
    Solution solution;
    vector<int> result = solution.findBuilding(heights);
    for (int i = 0; i < n; ++i) {
        cout << result[i] << " ";
    }
    system("pause");
    return 0;
}