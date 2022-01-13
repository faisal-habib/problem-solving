class Solution {
public:
	static bool _cmp(vector<int> &v1, vector<int> &v2) {
		return v1[1] < v2[1];
	}

    int findMinArrowShots(vector<vector<int>>& points) {
        int minimumRequiredArrow = 0;
		int pointsSz = points.size();

        sort(points.begin(), points.end(), _cmp);

		for(int i = 0; i < pointsSz; i++) {
            int currBalloonEnd = points[i][1];
			minimumRequiredArrow++;	// we need to shoot atleast 1 arrow to burst current baloon

            // now we'll search how many baloons fall whithin end of current baloon
			for(int j = i + 1; j < pointsSz; j++) {
                if (points[j][0] > currBalloonEnd) {
					i = j - 1;
					break;
				}
                else i++;
			}
		}
        return minimumRequiredArrow;
    }
};
