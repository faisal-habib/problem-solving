/*
Problem link:
https://practice.geeksforgeeks.org/problems/print-anagrams-together/1
https://leetcode.com/problems/group-anagrams/

Resources:
https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/
https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together-set-2/
*/
/**
Solution 1: requires sorting each string
Time: N*L*logL , L - length of given word, N - total number of words
*/
vector<vector<string> > Anagrams(vector<string>& string_list)
{
    int sz = string_list.size();
    string currS;
    unordered_map< string, vector<string> > mp;
    vector<vector<string> > output;

    for(int i=0; i<sz; i++)
    {
        currS = string_list[i];
        sort(currS.begin(), currS.end());

        mp[currS].push_back(string_list[i]);
    }

    unordered_map<string, vector<string>> :: iterator it;
    for(it=mp.begin(); it!=mp.end(); it++)
    {
        output.push_back(it->second);
    }
    return output;
}

/**
Solution 2: doesn't require sorting each string
Time: N * L, L - length of given word, N - total number of words
*/

vector<vector<string> > Anagrams(vector<string>& string_list)
{
    int sz = string_list.size();
    map< vector<int>, vector<string> > mp;  // in GFG, it's showing compiler error while used unordered_map instead
    vector<vector<string> > output;

    for(int i=0; i<sz; i++)
    {
        vector<int>vis(26,0);

        for(int j=0; string_list[i][j]; j++) vis[string_list[i][j]-'a']++;

        mp[vis].push_back(string_list[i]);
    }

    for(auto v:mp)
    {
        output.push_back(v.second);
    }
    return output;
}
