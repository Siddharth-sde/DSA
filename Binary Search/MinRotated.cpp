/*
    ## REVIEW
    Problem - 153. Find Minimum in Rotated Sorted Array

    Pattern:
    Modified Binary Search

    The main challenge in this problem was understanding how to find the
    minimum without simply traversing the entire array.

    The key idea was to compare nums[mid] with nums[high] to determine
    which side contains the minimum and eliminate the other half.

    Key Learning:
    Even in a rotated sorted array, I can use the sorted structure to
    eliminate half of the search space at every step.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        if (nums[low] <= nums[high]){
            return nums[0];
        }
        while (low <= high){
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[low]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
            if (nums[mid + 1] < nums[mid]){
                return nums[mid+1];
            }
            if (nums[mid] < nums[mid - 1]){
                return nums[mid];
            }
        }
    return -1;
    }
};