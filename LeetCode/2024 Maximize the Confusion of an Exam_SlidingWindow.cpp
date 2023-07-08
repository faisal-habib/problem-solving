class Solution {
public:
	void CalculateLengthByChangingCharacter(string &answerKey, int &sz, int &maxChangeLimit, char charToChange, int &maxLength) {
		int left = 0;
		int right = 0;
		int changedCharCount = 0;
		int currLength = 0;
		
		while(right < sz && left <= right) {
			if (answerKey[right] == charToChange) {
				if (changedCharCount == maxChangeLimit) {
					currLength = right - left;
					maxLength = currLength > maxLength ? currLength : maxLength;
					
					while(left <= right) {
						if (answerKey[left] == charToChange) break;
						else left++;
					}
					left++;
					changedCharCount--;
				}
				changedCharCount++;
			}
			right++;
		}
		currLength = right - left;
		maxLength = currLength > maxLength ? currLength : maxLength;
	}
	
    int maxConsecutiveAnswers(string answerKey, int k) {
		int sz = answerKey.size();
		int maxLength = 0;
		
		// check answer by changing 'F' to 'T'
		CalculateLengthByChangingCharacter(answerKey, sz, k, 'F', maxLength);
        
		// check answer by changing 'T' to 'F'
		CalculateLengthByChangingCharacter(answerKey, sz, k, 'T', maxLength);
		
		return maxLength;
    }
};