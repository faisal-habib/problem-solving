/**
Monotonic Stack is a special variation of the typical data structure Stack.
As its name shows, monotonic stack contains all features that a normal stack has and its elements are all monotonic decreasing or increasing.

If a problem is suitable to use monotonic stack, it must has at least three characters:

    It is a “range queries in an array” problem.
    The min/max element or the monotonic order of elements in a range is useful to get answer of every range query.
    When a element is popped from the monotonic stack, it will never be used again.

Problems to solve using monotonic stack:
https://leetcode.com/problems/largest-rectangle-in-histogram/
https://leetcode.com/problems/trapping-rain-water/
https://leetcode.com/problems/maximal-rectangle/

Resources:
https://medium.com/techtofreedom/algorithms-for-interview-2-monotonic-stack-462251689da8
https://www.programmersought.com/article/2213464744/
*/
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int sz = heights.size();
        vector<int>output(sz, 0);
        stack<int>stk;

        for(int i=sz-1; i>=0; i--) {
            int currH = heights[i], smallerCount = 0, ans = 0;
            if(stk.empty()) stk.push(currH);
            else {
                if(currH >= stk.top()) {

                    while(!stk.empty() && currH > stk.top()) {
                        stk.pop();
                        smallerCount++;
                    }

                    if(stk.size()) ans++;   // curr person can see the first bigger person to this right
                    ans += smallerCount;
                    stk.push(currH);
                }
                else {
                    if(stk.size()) ans++;
                    stk.push(currH);
                }
            }
            output[i] = ans;
        }
        return output;
    }
};
