/*
    ## REVIEW
    Problem - 33. Search in Rotated Sorted Array

    Pattern:
    Modified Binary Search

    The main challenge in this problem was understanding how to apply binary
    search when the array is rotated and is no longer completely sorted.

    The key observation was that at least one half of the array will always
    remain sorted. I can check which half is sorted and then determine whether
    the target lies within that range.

    Key Learning:
    Even when the entire array isn't sorted, binary search can still work if
    I can identify a sorted half and eliminate the other half.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = -1;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] == target){
                ans = mid;
                return ans;
            }
            else if (nums[mid] >= nums[low]){
                if (target < nums[mid] && target  >= nums[low]){
                high = mid - 1;
                }
                else{
                low = mid + 1;
                }
            }
            else{
                if (target > nums[mid] && target <= nums[high]){
                    low = mid + 1;
                }
                else{
                    high = mid - 1;
                }
            }
        }
        return ans;
    }
};