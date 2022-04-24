class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        int scoresSz = 0;
        int totalScore = 0;

        for(auto curr: ops) {
            if (curr == "+") {
                int sum = scores[scoresSz - 1] + scores[scoresSz - 2];

                scores.push_back(sum);
                scoresSz++;
            }
            else if (curr == "D") {
                scores.push_back(scores[scoresSz - 1] * 2);
                scoresSz++;
            }
            else if (curr == "C") {
                scores.pop_back();
                scoresSz--;
            }
            else {
                scores.push_back(stoi(curr));
                scoresSz++;
            }
        }

        for(auto curr : scores) {
            totalScore += curr;
        }

        return totalScore;
    }
};
