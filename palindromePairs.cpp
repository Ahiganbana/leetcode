#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    //哪两种字符串拼在一起可以回文
    //1. 字母顺序相反的可以互相组成回文串
    //2. 可以将两个字符串中较长的那个分解为一个回文串和另一个字串的翻转
    public:
    //暴力解法(超时)
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int size = words.size();
        int i,j,k = 0;
        vector<vector<int>> result;
        vector<int> tmp(2,0);
        for(i = 0; i < size; i++) {
            for(j = 0; j < size; j++) {
                string  s = words[i] + words[j];
                if(isPalindrome(s) && i != j) {
                    tmp[0] = i;
                    tmp[1] = j;
                    result.push_back(tmp);
                    k++;
                }
            }
        }
        return result;
    }

    //判断字符串是否是回文
     bool isPalindrome(string s)  {
        int size = s.length();
        int i = 0, j = size - 1;
        bool flag = false;
        while(i <= j) {
            if(s[i] == s[j]) {
                i++;
                 j--;
            }
            else{
                break;
            }
            if(i == j || i > j) {
                flag = true;
            }
        }
        return flag;
    }

    //字典树的结构
    struct node {
        int ch[26];
        int flag;
        node() {
            flag = -1;
            memset(ch,0,sizeof(ch));
        };

        vector<node> tree;

        void insert(string& s, int id) {
            int len = s.length(),add = 0;
            for(int i = 0; i < len; i++) {
                int x = s[i] - 'a';
                if(!tree[add].ch[x]) {
                    tree.emplace_back();
                    tree[add].ch[x] = tree.size() - 1;
                }
                add = tree[add].ch[x];
            }
            tree[add].flag = id;
        }

        int findWord(string& s, int left, int right) {
            int add = 0;
            for(int i = right; i >= left; i--) {
                int x = s[i] - 'a';
                if(!tree[add].ch[x]) {
                    return -1;
                }
                add = tree[add].ch[x];
            }
            return tree[add].flag;
        }

        bool isPalindrome(string& s, int left, int right) {
            int len = right - left + 1;
            for(int i = 0; i < len / 2; i++) {
                if(s[left + i] != s[right - i]) {
                    return false;
                }
            }
            return true;
        }

        vector<vector<int>> palindormePairs(vector<string>& words) {
            tree.emplace_back(node());
            int n = words.size();
            for(int i = 0; i < n; i++) {
                insert(words[i],i);
            }
            vector<vector<int>> ret;
            for(int i = 0; i < n; i++) {
                int m = words[i].size();
                for(int j = 0; j <= m; j++) {
                     if(isPalindrome(words[i], j, m - 1)) {
                        int left_id = findWord(words[i], 0, j - 1);
                        if(left_id != -1 && left_id != i) {
                            ret.push_back({i, left_id});
                        }
                    }
                    if(j && isPalindrome(words[i], 0, j - 1)) {
                        int right_id = findWord(words[i], j, m - 1);
                        if(right_id != -1 && right_id != i) {
                            ret.push_back({right_id, i});
                        }
                    }
                }
            }
            return ret;
        }
    }
};  

int main() {
    vector<string> words;
    int n;
    cin  >> n;
    words.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> words[i];
    }
    Solution soluti on;
    vector<v ector<int>> r esult = solution.palindromePairs(words);
    for(int i = 0; i < result.size(); i++) {
        for(int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
    }
    system("pause");
    return 0;
}    