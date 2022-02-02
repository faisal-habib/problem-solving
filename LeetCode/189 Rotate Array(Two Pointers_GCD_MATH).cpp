/*
Problem link:
https://leetcode.com/problems/rotate-array/
*/

class Solution {
public:
    void _reverse(vector<int> &nums, int startInd, int endInd) {
		while(startInd < endInd) {
			int temp = nums[startInd];
			nums[startInd] = nums[endInd];
			nums[endInd] = temp;
			startInd++;
			endInd--;
		}
	}
    
    void rotate(vector<int>& nums, int k) {
        int vecSz = nums.size();
		k %= vecSz;
		_reverse(nums, 0, vecSz - 1);
		_reverse(nums, 0, k - 1);
		_reverse(nums, k, vecSz - 1);
    }
};

/*
// Solution 2
class Solution {
public:
    int _gcd(int a, int b) {
        return b == 0 ? a : _gcd(b, a % b);
    }
    
    void _rotateRight(vector<int> &nums, int &vecSz, int &stepsToRotate) {
        stepsToRotate %= vecSz;
        //	required cycle to rotate all numbers
		int cycleCount = _gcd(vecSz, stepsToRotate);
        
        for(int i = 0; i < cycleCount; i++) {
            int startInd = i;
            int startingVal = nums[startInd];
            int nextInd;
            while(true) {
                nextInd = startInd + stepsToRotate;
                if (nextInd >= vecSz) {
                    nextInd -= vecSz;
                }
                if (nextInd == i) {
                    break;
                }
                
                int temp = nums[nextInd];
                nums[nextInd] = startingVal;
                
                startInd = nextInd;
                startingVal = temp;
            }
            nums[nextInd] = startingVal;
        }
    }
    
    void rotate(vector<int>& nums, int k) {
        int vecSz = nums.size();
        if (vecSz > 1) _rotateRight(nums, vecSz, k);
    }
};
*/