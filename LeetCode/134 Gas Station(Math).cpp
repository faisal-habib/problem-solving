/*
Problem:
https://leetcode.com/problems/gas-station/

Idea:
if we can't reach to index y from index x, that means we can't reach to index y from index x + 1, x + 2 ...
so rather than checking from index x + 1 again, we'll start from journey from y.
It means that, if we run out of fuel say at some ith gas station, all the gas station between ith and starting point are bad starting point as well.
So, we'll start trying from next gas station.
Complexity: O(N)
*/

class Solution {
public:
    void _checkIfSolutionExists(vector<int>& gas, vector<int>& cost, int &totalStation, int &startIndex, int &endIndex) {
        int currentlyRemainingGas = gas[startIndex];
        int currIndex = startIndex;

        while(endIndex != startIndex) {
            int nextIndex = currIndex + 1 < totalStation ? currIndex + 1 : 0;
            if (currentlyRemainingGas - cost[currIndex] < 0) return ;

            // we can go to next position
            currentlyRemainingGas -= cost[currIndex];
            currentlyRemainingGas += gas[nextIndex];
            endIndex = nextIndex;
            currIndex = nextIndex;
        }
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalStation = gas.size();
        int totalGasAmount = 0;
        int totalCost = 0;

        for(int i = 0; i < totalStation; i++) {
            totalGasAmount += gas[i];
            totalCost += cost[i];
        }

        if (totalGasAmount < totalCost) return -1;

        for(int i = 0; i < totalStation; i++) {
            int startIndex = i;
            int endIndex = -1;
            _checkIfSolutionExists(gas, cost, totalStation, startIndex, endIndex);

            if (endIndex == i) return i;
            else if (endIndex != -1) i = endIndex - 1;
        }

        return -1;
    }
};
