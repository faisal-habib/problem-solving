// Solution 1: Soring based solution

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int sz = weights.size();
		vector<int> pairWeight;
		for(int i = 0; i < sz - 1; i++) {
			pairWeight.push_back(weights[i] + weights[i + 1]);
		}
		
		sort(pairWeight.begin(), pairWeight.end());
		
		long diffBetweenMaxMinScore = 0;
		
		for(int i = 0, j = sz - 2; i < k - 1; i++, j--) {
			diffBetweenMaxMinScore += (pairWeight[j] - pairWeight[i]);
		}
		
		return diffBetweenMaxMinScore;
    }
};