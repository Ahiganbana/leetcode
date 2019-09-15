#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        bool isPalindrome(int x){
            vector<int> nums;
            bool flag = true;
            int i, j;
            if( x < 0){
                flag = false;
            }
            else if(x / 10 == 0){
                flag = true;
            }
            else{
                int num = x;
                int d = 0;
                while(num != 0){
                    d = num % 10;
                    num /= 10;
                    nums.push_back(d);
                }
                for (i = 0, j = nums.size() - 1; i < j; ++i,--j){
                    if(nums[i] != nums[j]){
                        flag = false;
                    }
                }
            }
            return flag;
        }
};

int main(){
    int num;
    cin >> num;
    Solution solution;
    bool result = solution.isPalindrome(num);
    if(result)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    system("pause");
    return 0;
}

