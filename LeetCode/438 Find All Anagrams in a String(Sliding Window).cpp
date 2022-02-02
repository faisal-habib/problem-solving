/*
Problem link:
https://leetcode.com/problems/find-all-anagrams-in-a-string/
*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        // s -> query string
        // p -> target string
        int sLen = s.size();
        int pLen = p.size();
        int letterCountOfP[26] = {0};
        vector<int>startIndices;
        
        for(int i = 0; i < pLen; i++) letterCountOfP[p[i] - 'a']++;
        
        if (sLen < pLen) return startIndices;
        
        int left = 0;
        int right = 0;
        
        while(right < sLen) {
            int currLetterId = s[right] - 'a';
            letterCountOfP[currLetterId]--;
            
            while(letterCountOfP[currLetterId] < 0 && left <= right) {
                letterCountOfP[s[left] - 'a']++;
                left++;
            }
            
            if (right - left + 1 == pLen) {
                startIndices.push_back(left);
                letterCountOfP[s[left] - 'a']++;
                left++;
            }
            
            right++;
        }
        
        return startIndices;
    }
};