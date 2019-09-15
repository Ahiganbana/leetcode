#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution{
public:
    int romanToInt(string s){
        //int num = 0;
        vector<int> nums;
        int sum = 0;
        for (int i = 0; i < s.length(); i++){
            if(s[i] == 'I'){
                if(s[i+1] == 'V'){
                    nums.push_back(4);
                    i++;
                }else if(s[i+1] == 'X'){
                    nums.push_back(9);
                    i++;
                }
                else{
                    nums.push_back(1);
                }
            }
            else if(s[i] == 'V'){
                nums.push_back(5);
            }
            else if(s[i] == 'X'){
                if(s[i+1] == 'L'){
                    nums.push_back(40);
                    i++;
                }else if(s[i+1] == 'C'){
                    nums.push_back(90);
                    i++;
                }
                else{
                    nums.push_back(10);
                }
            }
            else if(s[i] == 'L'){
                nums.push_back(50);
            }
            else if(s[i] == 'C'){
                if(s[i+1] == 'D'){
                    nums.push_back(400);
                    i++;
                }else if(s[i+1] == 'M'){
                    nums.push_back(900);
                    i++;
                }
                else{
                    nums.push_back(100);
                }
            }
            else if(s[i] == 'D'){
                nums.push_back(500);
            }
            else if(s[i] == 'M'){
                nums.push_back(1000);
            }
        }
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        return sum;
    }

    int romanToInt2(string s){
        map<string, int> m = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, 
            {'C', 100}, {'D', 500}, {'M', 1000}, {'IV',4},{'IX',9},{'XL',40},{'XC',90}
            {'CD',400},{'CM',900}};
        int r = m[s.substr(0, 1)];
        for (int i = 0; i < s.length(); ++i){
            string one = s.substr(i, 1);
            string two = s.substr(i - 1, 2);
            r += m[two] ? m[two] : m[one];
        }
        return r;
    }
};
int main(){
    string input;
    cin >> input;
    Solution solution;
    int result = solution.romanToInt(input);
    cout << result << endl;
    system("pause");
    return 0;
}