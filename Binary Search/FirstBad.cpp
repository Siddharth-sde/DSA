/*
    ## REVIEW
    Problem - 278. First Bad Version

    Pattern:
    Binary Search - Finding Boundary

    The main idea was to treat the versions as a search space instead of
    searching through an array. Since once a version is bad, every version
    after it will also be bad, there is a clear false -> true pattern.

    If mid is bad:
        Store/search on the left because there may be an earlier bad version.

    If mid is good:
        Search on the right because the first bad version must come later.

    Key Learning:
    Binary search can be used to find a boundary in a monotonic true/false
    pattern even when there is no array to search.
*/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
// isBadVersion() is provided by LeetCode.
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        int low = 0; 
        int high = n;
        int firstInstance = n;
        while(low<=high){
            int mid = low + (high - low) / 2;
            if (isBadVersion(mid)){
                if (firstInstance > mid){
                    firstInstance = mid;
                }
                high = mid - 1;  
            }
            else{
                low = mid+1;
            }
        }
        return firstInstance;
    }
};