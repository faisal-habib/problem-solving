/*
Problem:
https://leetcode.com/problems/koko-eating-bananas/
*/

class Solution {
public:
    int _getRequiredHoursToEatAllBanana(vector<int>& piles, int &pilesSize, int &eatingSpeed) {
        int totalRequiredHours = 0;
        for(int i = 0; i < pilesSize; i++) {
            int curr = piles[i] / eatingSpeed;
            if (piles[i] % eatingSpeed) curr++;

            totalRequiredHours += curr;
        }
        return totalRequiredHours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int pilesSize = piles.size();
        int minK = INT_MAX;
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = low + ((high - low) >> 1);
            int requiredHours = _getRequiredHoursToEatAllBanana(piles, pilesSize, mid);

            if (requiredHours > h) {
                // need to increase eating speed
                low = mid + 1;
            }
            else {
                high = mid - 1;
                minK = mid < minK ? mid : minK;
            }
        }
        return minK;
    }
};
