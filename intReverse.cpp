#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        vector<int> nums;
        int num = x;
        int d = 0;
        int result = 0;
        long long tmp = 0;
        if ((num >= pow(2, 31) - 1) || num <= -pow(2, 31))
        {
            result = 0;
        }
        else
        {
            while (num != 0)
            {
                d = num % 10;
                num = num / 10;
                nums.push_back(d);
            }
            for (int i = 0; i < nums.size(); i++)
            {
                tmp += nums[i] * pow(10, nums.size() - i - 1);
            }
        }
        //cout << tmp << endl;
        if ((tmp <= pow(2, 31) - 1) && tmp >= -pow(2, 31))
        {
            result = tmp;
        }
        else
        {
            result = 0;
        }
        return result;
    }
};

int main(){
    int num = 0;
    cin >> num;
    Solution solution;
    int result = solution.reverse(num);
    cout << result << endl;

    system("pause");
    return 0;
}