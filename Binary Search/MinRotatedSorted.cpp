/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
/*
    ## REVIEW
    Problem - 374. Guess Number Higher or Lower

    Pattern:
    Binary Search

    The main idea was similar to normal binary search, but instead of
    comparing nums[mid] with a target directly, I use the provided API
    to determine whether my guess is too high, too low, or correct.

    If the guess is too high:
        Search on the left.

    If the guess is too low:
        Search on the right.

    If the guess is correct:
        Return mid.

    Key Learning:
    Binary search can also be applied when an API tells me which half
    of the search space can be eliminated.
*/

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int guessNumber(int n) {
        int low = 0;
        int high = n;
        while (low <= high){
            int mid = low + (high - low) / 2;
            if ( guess(mid) == 0){
                return mid;
            }
            else if(guess(mid) == -1){
                high = mid - 1;
            }
            else if(guess(mid)){
                low = mid + 1;
            }
        }
        return 0;
    }
};