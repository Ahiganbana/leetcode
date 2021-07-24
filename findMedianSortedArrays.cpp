#include <iostream>
#include <vector>
using namespace std;

//找到两个有序数组之间的中位数
class Solution {
public:
    //问题转化为求两个数组中第k小的数
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;
        
        while(true) {
            if(index1 == m) {
                return nums2[index2 + k - 1];
            }
            if(index2 == n) {
                return nums1[index1 + k - 1];
            }
            if(k == 1) {
                return min(nums1[index1], nums2[index2]);
            }

            int newIndex1 = min(index1 + k / 2 - 1, m - 1);
            int newIndex2 = min(index2 + k / 2 - 1, n - 1);
            int pivot1 = nums1[newIndex1];
            int piovt2 = nums2[newIndex2];
            if(pivot1 <= piovt2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }else{
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if(totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        }else{
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }
};