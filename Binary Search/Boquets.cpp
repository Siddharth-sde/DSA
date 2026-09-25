#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        long long nf = 1LL * m * k;
        int ans = 0;
        if (nf > size){
            return -1;
        }
        int low = *min_element(bloomDay.begin(),bloomDay.end());
        int high = *max_element(bloomDay.begin(),bloomDay.end());
        while (low <= high){
            int boquet = 0, adjacent = 0;
            int mid = low + (high - low) / 2;
            for(int i = 0; i < size; i++){
                if (mid >= bloomDay[i]){
                    adjacent++;
                    if (adjacent == k){
                        boquet++;
                        adjacent = 0;
                    }
                }
                else{
                    adjacent = 0;
                }
            }
            if (boquet >= m){
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};


/* ## REVIEW
   Problem - 1482. Minimum Number of Days to Make m Bouquets

   The biggest hurdle I faced in this question was finding out logic for adjacent flowers
   which was actually easy if I would've noticed it earlier. The neat part was realising 
   that the range for binary search won't always lie on index but also the search space 
   will differ according to the requiremenets.
*/