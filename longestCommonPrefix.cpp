#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
public:
    string longestCommonPrefix(vector<string>& strs){
        if(strs.size() == 0){
            return "";
        }
        if(strs.size() == 1){
            return strs[0];
        }
        int index = -1;
        bool flag = false;
        string prefix;
        string common = strs[0];
        for (int i = 0; i < strs.size();i++){
            int j = 0;
            for (; j < common.length() && j < strs[i].length();j++){
                if(common[j] != strs[i][j]){
                    break;
                }
            }
            common = common.substr(0, j);
            if(common == "")
                return common;
        }
        return common;
    }
        
};

int main(){
    vector<string> input;
    string str;
    while(cin >> str && str != "end"){
        input.push_back(str);
    }
    Solution solution;
    string result = solution.longestCommonPrefix(input);
    cout << result << endl;
    system("pause");
    return 0;
}