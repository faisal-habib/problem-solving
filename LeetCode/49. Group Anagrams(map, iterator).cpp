/*
Problem link:
https://leetcode.com/problems/group-anagrams/
https://practice.geeksforgeeks.org/problems/print-anagrams-together/1

Resources:
https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/
https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together-set-2/
*/
/**
Solution 1: requires sorting each string
Time: N*L*logL , L - length of given word, N - total number of words
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int inSz=strs.size(),i,j,len;
        string s;
        vector<vector<string>>output;
        unordered_map< string,vector<string> >mp;

        for(i=0;i<inSz;i++)
        {
            s=strs[i];
            sort(s.begin(),s.end());
            mp[s].push_back(strs[i]);
        }

        unordered_map< string,vector<string> >::iterator it;
        for(it=mp.begin();it!=mp.end();it++)
        {
            output.push_back(it->second);
        }
        return output;
    }
};

/**
Solution 2: doesn't require sorting each string
Time: N * L, L - length of given word, N - total number of words
*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        int inSz=strs.size(),i,j,len;
        vector<vector<string>>output;
        map< vector<int>,vector<string> >mp;

        for(i=0;i<inSz;i++)
        {
            vector<int>vis(26,0);

            for(j=0; strs[i][j]; j++) vis[strs[i][j]-'a']++;

            mp[vis].push_back(strs[i]);
        }

        for(auto v:mp)
        {
            output.push_back(v.second);
        }
        return output;
    }
};
