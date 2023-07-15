class Solution {
public:
	static bool CMP(vector<int> &event1, vector<int> &event2) {
		if (event1[0] < event2[0]) return true;
		return false;
	}
	
	int GetNextEventIndexUsingBinarySearch(vector<vector<int>> &events, int &totalEvents, int &endTimeOfPrevEvent) {
		int left = 0;
		int right = totalEvents;
		while(left < right) {
			int mid = left + ((right - left) >> 1);
			if (events[mid][0] <= endTimeOfPrevEvent) {
				left = mid + 1;
			}
			else {
				right = mid;
			}
		}
		return left;
	}
	
	int GetMaxSumOfValues(int currIndex, int remainingEventToAttend, int &totalEvents, vector<vector<int>> &events, vector<vector<int>> &dp) {
		if (remainingEventToAttend == 0 || currIndex == totalEvents) {
			return 0;
		}
		
		int &currSumOfValues = dp[remainingEventToAttend][currIndex];
		if (currSumOfValues != -1) {
			return currSumOfValues;
		}
		
		int nextEventIndex = GetNextEventIndexUsingBinarySearch(events, totalEvents, events[currIndex][1]);
		int withCurrentEvent = events[currIndex][2] + GetMaxSumOfValues(nextEventIndex, remainingEventToAttend - 1, totalEvents, events, dp);
		int withOutCurrentEvent = GetMaxSumOfValues(currIndex + 1, remainingEventToAttend, totalEvents, events, dp);
		
		return currSumOfValues = max(withCurrentEvent, withOutCurrentEvent);
	}
	
    int maxValue(vector<vector<int>>& events, int k) {
        int maxSumOfValues = 0;
		int totalEvents = events.size();
		vector<vector<int>> dp(k+1, vector<int> (totalEvents, -1));
		
		// sorting increasingly based on event's start time
		sort(events.begin(), events.end(), CMP);
		
		return GetMaxSumOfValues(0, k, totalEvents, events, dp);
    }
};