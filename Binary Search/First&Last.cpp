/*
    ## REVIEW
    Problem - 34. Find First and Last Position of Element in Sorted Array

    Pattern:
    Binary Search - Finding Boundaries

    The main thing I learned from this problem was that normal binary search
    can be modified to find the first or last occurrence instead of stopping
    as soon as the target is found.

    For the first occurrence:
    If target is found, store the index and continue searching towards the left.

    For the last occurrence:
    If target is found, store the index and continue searching towards the right.

    Key Learning:
    Finding the target is not always the final goal. Sometimes I need to keep
    searching after finding it to find the required boundary.
*/

#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> arr;
        arr.push_back(FirstOccur(nums,target));
        arr.push_back(LastOccur(nums,target));
        return arr;
    };
    int FirstOccur(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                ans = mid;
                high = mid - 1;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
        }
        return ans;
    };
    int LastOccur(vector<int>& nums,int target){
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                ans = mid;
                low = mid + 1;
            }
            else if (nums[mid] > target){
                high = mid - 1;
            }
            else if (nums[mid] < target){
                low = mid + 1;
            }
        }
        return ans;
    };
};


