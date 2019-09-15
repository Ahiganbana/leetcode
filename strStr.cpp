#include<iostream>
#include<string>
using namespace std;

class Solution{
    public:
    int strStr(string haystack, string needle){
        if(needle.empty()){
            return 0;
        }
        if((haystack.size() >= needle.size()) && (needle.size() != 0)){
            for(int i = 0;i<haystack.size();i++){
            if(haystack[i] == needle[0]){
                string tmp = haystack.substr(i,needle.size());
                if(tmp == needle)
                    return i;
                }
            }
        }
        
        return -1;
    }
};

int main(){
    Solution solution;
    string str1,str2;
    cin >> str1>>str2;
    int result = solution.strStr(str1, str2);
    cout << result << endl;
    system("pause");
    return 0;
}