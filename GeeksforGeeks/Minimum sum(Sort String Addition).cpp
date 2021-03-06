/*
Problem:
https://practice.geeksforgeeks.org/problems/minimum-sum4058/1
*/

class Solution{
public:
    string _getAddition(string s1, string s2) {
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());

        int sz1 = s1.size(), sz2 = s2.size();
        int carry = 0, sum = 0;
        string sumString="";

        for(int i=0; i<sz1 || i<sz2; i++) {
            sum = carry;
            if(i<sz1) sum+= (s1[i]-'0');
            if(i<sz2) sum+= (s2[i]-'0');

            sumString+= to_string((sum%10));
            carry = sum/10;
        }
        if(carry) sumString+= to_string(carry);

        reverse(sumString.begin(), sumString.end());
        //remove leading 0
        int count = 0;
        for(int i=0; sumString[i]; i++) {
            if(sumString[i]=='0') count++;
            else break;
        }

        if(count) sumString.erase(0, count);
        return sumString;
    }
    string solve(int arr[], int n) {
        sort(arr, arr+n);

        string s1="", s2="";
        for(int i=0; i<n; i++) {
            // To avoid leading 0, if string is empty and current value is 0, then don't insert into string.
            if( i%2==0 && (!s1.empty() ||arr[i]!=0) ) s1+=to_string(arr[i]);
            else if( i%2==1 && (!s2.empty() ||arr[i]!=0) ) s2+=to_string(arr[i]);
        }

        string s = _getAddition(s1, s2);
        return s;
    }
};
