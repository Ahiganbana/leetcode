#include <iostream>
#include <vector>
#include <string>
using namespace std;

//将字符串划分为片段,同一字母最多出现在一个片段中
class Solution {
public:
    vector<int> partitionLabels(string S) {
        //统计每个字母出现的次数
        vector<int> freq(26, 0);
        vector<int> results;
        int size = S.length();
        for (int i = 0; i < size; ++i) {
            freq[S[i] - 'a']++;
        }

        //滑动窗口
        int left = 0, right = 0, index = 0, result = 0;
        //判断窗口内每个字母次数是否用尽为0
        while(left < size){
            freq[S[right] - 'a']--;
            right++;
            index = left;
            while(index < right){
                if(freq[S[index] - 'a'] != 0){
                    break;
                }else{
                    index++;
                }
            }
            if(index == right){
                result = right - left;
                results.push_back(result);
                left = right;
            }
        }
        return results;
    }

    //方法而: 记录每个字符最后一次出现的下标.每个滑动窗口中,依次判断每个字母最后一次出现的位置,如果在一个下标内,所有字母的最后一次出现的位置都包含进来了,这个下标就是满足条件的窗口大小.
    vector<int> partitionLabels(string S){

    }
};

int main() {
    Solution solution;
    string s;
    cin >> s;
    vector<int> result;
    result = solution.partitionLabels(s);
    for (int i = 0; i < result.size(); i++){
        cout << result[i] << ",";
    }
    system("pause");
    return 0;
}