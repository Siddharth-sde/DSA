/*
## REVIEW
Problem - 20. Valid Parentheses

Pattern:
Stack - Matching & Balancing Parentheses

The main idea was to use a stack to keep track of opening brackets
and match each closing bracket with the most recently encountered
opening bracket.

Problems I faced:
- Handling closing brackets when the stack was empty.
- Making sure each closing bracket matched the correct opening bracket.
- Understanding why the most recently opened bracket must be closed first.
- Ensuring no unmatched opening brackets remained after traversal.
- Managing the conditions for matching all three types of brackets.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> st;
        for(int i = 0; i < len; i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
            }
            else{
                if (st.empty())
                    return false;
                if (s[i] ==')' && st.top() == '(' || s[i] ==']' && st.top() == '[' || s[i] =='}' && st.top() == '{'){
                    st.pop();
                }
                else
                    return false;
            }
        }
        return st.empty();
    }
};