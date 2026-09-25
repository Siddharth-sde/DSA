/*
    ## REVIEW
    Problem - 35. Search Insert Position

    Pattern:
    Binary Search

    This was a fairly straightforward binary search problem. The main thing
    I learned was that even when the target is not present, binary search can
    still be used to find the correct position where it should be inserted.

    Key Learning:
    If the target is smaller than nums[mid], search on the left.
    If it is larger, search on the right.
    When the loop ends, low represents the position where the target should
    be inserted.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                return mid;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
        }
        return low;
    }
};