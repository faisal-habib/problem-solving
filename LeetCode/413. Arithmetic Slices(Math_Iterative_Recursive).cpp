/*
Problem link:
https://leetcode.com/problems/arithmetic-slices/
*/

// O(N) iterative solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int inputSz = nums.size();
        if (inputSz <3) return 0;
        
        int arithmaticSubarrayCount = 0;
        int currCount = 0;
        for(int i = inputSz - 1; i >= 2; i--) {
            if (nums[i] - nums[i-1] == nums[i-1] - nums[i-2]) {
                currCount++;
                arithmaticSubarrayCount += currCount;
            }
            else currCount = 0;
        }
        return arithmaticSubarrayCount;
    }
};

/*
// O(N) recursive solution
class Solution {
public:
    int _getArithmaticSubarrayCount(vector<int> &nums, int currInd, int &ans) {
        if (currInd < 2) return 0;
        
        int result = 0;
        if (nums[currInd] - nums[currInd-1] == nums[currInd-1] - nums[currInd-2]) {
            result = 1 + _getArithmaticSubarrayCount(nums, currInd - 1, ans);
            ans += result;
        }
        else _getArithmaticSubarrayCount(nums, currInd - 1, ans);
        
        return result;
    }
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        int inputSz = nums.size();
        if (inputSz <3) return 0;
        
        int arithmaticSubarrayCount = 0;
        _getArithmaticSubarrayCount(nums, inputSz - 1, arithmaticSubarrayCount);
        return arithmaticSubarrayCount;
    }
};
*/

/*
// O(N^2) iterative solution
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int inputSz = nums.size();
        if (inputSz <3) return 0;
        
        int currDiff;
        int arithmaticSubarrayCount = 0;
        
        for(int i = 0; i < inputSz; i++) {
            for(int j = i + 1; j < inputSz; j++) {
                if (j == i + 1) currDiff = nums[j] - nums[i];
                else if (nums[j] - nums[j-1] != currDiff) break;
                
                if (j - i + 1 >= 3) arithmaticSubarrayCount++;
            }
        }
        
        return arithmaticSubarrayCount;
    }
};

*/