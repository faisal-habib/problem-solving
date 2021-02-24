/*
Problem:
https://practice.geeksforgeeks.org/problems/subset-sums2234/1

Resources:
https://afteracademy.com/blog/print-all-subsets-of-a-given-set
*/
/**
Time: O( 2^n)
Space: O(n) for extra array subset.
*/

class Solution
{
public:
    void _getAllSubsetSum(vector<int>arr, int N, int currPos, int currSum, vector<int>&sumOfSubsets)
    {
        if(currPos==N)
        {
            sumOfSubsets.push_back(currSum);
            return ;
        }
        // include value of current position in sum
        _getAllSubsetSum(arr, N, currPos+1, currSum+arr[currPos], sumOfSubsets);

        // don't include value of current position in sum
        _getAllSubsetSum(arr, N, currPos+1, currSum, sumOfSubsets);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>sumOfSubsets;
        _getAllSubsetSum(arr, N, 0, 0, sumOfSubsets);
        sort(sumOfSubsets.begin(), sumOfSubsets.end());
        return sumOfSubsets;
    }
};
