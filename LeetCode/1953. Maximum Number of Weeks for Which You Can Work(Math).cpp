/*
Idea -
if the max elements is larger than the sum of the rest elements. then the max answer is 2 * rest + 1, because the best strategy is pick max, pick other, pick max, pick other....pick max. otherwise, we can finish all of the milestones.
*/

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxWeeks = 0, sz = milestones.size(), maxValue = 0, sum = 0;

        for(int i=0; i < sz; i++) {
            sum += milestones[i];
            maxValue = maxValue >= milestones[i] ? maxValue : milestones[i];
        }

        long long remSum = sum - maxValue;
        maxWeeks = (remSum << 1) + 1;
        maxWeeks = maxWeeks <= sum ? maxWeeks : sum;

        return maxWeeks;
    }
};
