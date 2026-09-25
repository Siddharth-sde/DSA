class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 0;
        int size = piles.size() - 1;
        for (int i  = 0; i <= size; i++){
            if (piles[i] > high){
                high = piles[i];
            }
        };
        int ans = high;
        while (low <= high){
            int mid = low + (high - low) / 2;
            double sum = 0;
            for (int i = 0; i <= size; i++ ){
                sum += (piles[i] + mid - 1) / mid;
            }
            if (sum <= h){
                ans = mid;
                high = mid - 1;
            }
            else if(sum > h){
                low = mid + 1;
            }
        }
        return ans;
    }
};




/*  ## Review :-
    Problem - 875. Koko Eating Bananas
    The main challange I faced during the solution of this problem was finding out what
    pattern it follows. Trying to figure out what I'm supposed to do was fairly complicated.
    ding the search space was decently easy after identifying that the answer is the eating speed. */ 
   