/*
## REVIEW
Problem - 682. Baseball Game

Pattern:
Stack - Simulation & Score Management

The main idea was to use a stack to maintain the scores
and process each operation according to its given rules.

Problems I faced:
- Understanding how to differentiate numeric strings from special operations.
- Converting string values into integers using stoi().
- Accessing the second-last score using stack operations.
- Temporarily popping and restoring elements while calculating the sum.
- Understanding that stacks don't support direct indexing or traversal.
- Calculating the final sum of all valid scores.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int length = operations.size();
        for(int i = 0 ; i < length; i++){
            if (operations[i] == "C")
                st.pop();
            else if(operations[i] == "D")
                st.push(st.top() * 2);
            else if(operations[i] == "+"){
                int a = st.top();
                st.pop();
                int sum = a + st.top();
                st.push(a);
                st.push(sum);
            }
            else{
                st.push(stoi(operations[i]));
            }
        }
        int a,sum = 0;
        int l = st.size();
        for (int i = 0; i < l; i++){
            a = st.top();
            sum += a;
            st.pop();
        }
        return sum;
    }
};