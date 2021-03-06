/*
Problem:
https://practice.geeksforgeeks.org/problems/find-smallest-range-containing-elements-from-k-lists/1#
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
Resources:
https://www.geeksforgeeks.org/find-smallest-range-containing-elements-from-k-lists/
*/

/*
Idea is to keep track of max & min value in each iteration.
As we're maintaining a min heap, we can know min value from root of the heap.
So keep additional track of max value.
*/

class Solution
{
public:
    typedef struct
    {
        int val, nextInd, listNum;
    }Info;
    struct Compare
    {
        bool operator()(Info const & p1, Info const & p2) {
            return p1.val > p2.val;
        }
    };

    void _solve(vector<vector<int>>&nums, vector<int>&ansRange)
    {
        int minVal = INT_MAX, maxVal = INT_MIN, currRange = INT_MAX;
        int startVal, endVal;

        int totalList = nums.size();

        priority_queue<Info, vector<Info>, Compare>pq;
        int currInd = 0;
        for(int i=0; i<totalList; i++)
        {
            Info info;
            info.val = (nums[i][currInd]); // inserting negative value
            info.listNum = i;
            info.nextInd = 1;

            pq.push(info);
            maxVal = nums[i][currInd]>maxVal ? nums[i][currInd]:maxVal;
        }

        while(true)
        {
            Info top = pq.top();
            pq.pop();

            minVal = (top.val);
            if((maxVal-minVal+1)<currRange)
            {
                startVal = minVal;
                endVal = maxVal;
                currRange = maxVal-minVal+1;
            }

            int currList = top.listNum;
            if( top.nextInd<nums[currList].size() )
            {
                currInd = top.nextInd-1;
                top.val = (nums[currList][currInd+1]);
                top.nextInd++;

                maxVal = nums[currList][currInd+1]>maxVal ? nums[currList][currInd+1]:maxVal;
                pq.push(top);
            }
            else
            {
                break;
            }
        }

        ansRange.push_back(startVal);
        ansRange.push_back(endVal);
    }

    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        vector<int>ansRange;
        _solve(nums, ansRange);
        return ansRange;
    }
};
