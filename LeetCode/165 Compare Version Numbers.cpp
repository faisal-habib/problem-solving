/*
Problem link:
https://leetcode.com/problems/compare-version-numbers/
*/

class Solution {
public:
    void _removeLeadingZero(string &currRevision) {
        string temp = "";
        int ind = 0;
        while(currRevision[ind] && currRevision[ind] == '0') ind++;
        
        if (currRevision[ind]) {
            while(currRevision[ind]) temp += currRevision[ind], ind++;
        }
        else temp = "0";
        currRevision = temp;
    }
    
    int _compare(string &rev1, string &rev2) {
        int ind = 0;
        int sz1 = rev1.size();
        int sz2 = rev2.size();
        
        if (sz1 < sz2) return -1;
        if (sz1 > sz2) return 1;
        
        while(rev1[ind] && rev2[ind]) {
            if (rev1[ind] < rev2[ind]) return -1;
            else if (rev1[ind] > rev2[ind]) return 1;
            ind++;
        }
        return 0;
    }
    
    int compareVersion(string version1, string version2) {
        string currRevision = "";
        vector<string> revision1;
        vector<string> revision2;
        int equal = 0;
        int smaller = -1;
        int larger = 1;
        
        for(char curr: version1) {
            if (curr == '.') {
                _removeLeadingZero(currRevision);
                revision1.push_back(currRevision);
                currRevision = "";
            }
            else currRevision += curr;
        }
        if (currRevision.size()) {
            _removeLeadingZero(currRevision);
            revision1.push_back(currRevision);
            currRevision = "";
        }
        
        currRevision = "";
        for(char curr: version2) {
            if (curr == '.') {
                _removeLeadingZero(currRevision);
                revision2.push_back(currRevision);
                currRevision = "";
            }
            else currRevision += curr;
        }
        if (currRevision.size()) {
            _removeLeadingZero(currRevision);
            revision2.push_back(currRevision);
            currRevision = "";
        }
        
        int sz1 = revision1.size();
        int sz2 = revision2.size();
        while(sz1 < sz2) {
            revision1.push_back("0");
            sz1++;
        }
        while(sz2 < sz1) {
            revision2.push_back("0");
            sz2++;
        }
        
        for(int i = 0; i < sz1; i++) {
            int cmp = _compare(revision1[i], revision2[i]);
            if (cmp == smaller) return smaller;
            else if (cmp == larger) return larger;
        }
        return equal;
    }
};