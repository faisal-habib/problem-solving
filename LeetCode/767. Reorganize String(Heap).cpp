/*
Problem: https://leetcode.com/problems/reorganize-string/
Resources: https://leetcode.com/problems/reorganize-string/solution/
*/

/**
Approach: 1
Using Heap/Priority Queue

Time: O(N log A)
N- size of String
A- size of Alphabet
As A is fixed(26), so time will be O(N)
Space: O(A), as A is fixed(26), so space will be O(1)
*/

class Solution {
public:
    string reorganizeString(string S) {
        int letterCount[26], sz = 0;
        for(int i=0; i<26; i++) letterCount[i] = 0;
        for(int i=0; S[i]; i++) {
            letterCount[S[i]-'a']++;
        }
        priority_queue< pair<int, int> >pq;
        for(int i=0; i<26; i++) {
            if(letterCount[i]) pq.push({letterCount[i], i});
        }

        string output = "";
        while(!pq.empty()) {
            pair<int,int>mx = pq.top();
            pq.pop();
            mx.first--;
            output+=(mx.second+'a');
            sz++;

            if(!pq.empty()) {
                pair<int,int>secMx = pq.top();
                pq.pop();
                secMx.first--;
                output+=(secMx.second+'a');
                sz++;
                if(secMx.first) pq.push(secMx);
            }

            if(mx.first) pq.push(mx);
        }

        for(int i=1; i<sz; i++) {
            if(output[i]==output[i-1]) return "";
        }
        return output;
    }
};
