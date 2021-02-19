class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int sz = s.size();
        if(!sz) return s;

        stack<int>openingBracketIndex;

        for(int i=0; i<sz; i++) {
            if(s[i]=='(') openingBracketIndex.push(i);
            else if(s[i]==')') {
                if(openingBracketIndex.empty()) s[i] = '#'; // there's no opening bracket, so current closing bracket is invalid
                else openingBracketIndex.pop();
            }
        }
        // if the stack still contains opening brackets, that means they don't have any pair, so they're invalid
        while(!openingBracketIndex.empty()) {
            int ind = openingBracketIndex.top();
            openingBracketIndex.pop();
            s[ind] = '#';
        }

        string output = "";
        for(int i=0; i<sz; i++) {
            if(s[i]!='#') output+=s[i];
        }

        return output;
    }
};
