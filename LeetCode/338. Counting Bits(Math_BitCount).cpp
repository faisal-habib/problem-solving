/*
Problem link:
https://leetcode.com/problems/counting-bits/
*/

/*
Idea:
Let if we have X and Y in Such a way that,
X/2 = Y
then Number of set bits in X - Number of set bit in Y <= 1

if X is ODD
    then the (LSB) Least Significant Bit will always be set and dividing by 2 means right shifting the number by 1 bit.
    so if last bit is set and right shift it by 1 bit than the last set bit will be lost.
    therfore the new number Y has 1 set bit less than in compare to X

But if X is Even
    then LSB will be equal to 0, therefore even we do right shift by1 bit then only this 0 bit will be lost and no set bit got lost

so When we have X has Even,
    no of set bit in X = no of set bit in Y

and When X is ODD
    no of set bit in X = 1 + no of set bit in Y
*/

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        result[0] = 0;
        
        for(int i = 1; i <= n; i++) {
            result[i] = result[i/2] + (i % 2);
        }
        
        return result;
    }
};

/*
class Solution {
public:
    int _getOneCount(int num) {
        int oneCount = 0;
        while(num) {
            oneCount += (num % 2);
            num /= 2;
        }
        return oneCount;
    }
    
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++) {
            result.push_back(_getOneCount(i));
        }
        return result;
    }
};
*/

/*
class Solution {
public:
    int _getOneCount(int num) {
        int oneCount = 0;
        while(num) {
            num &= (num - 1);
            oneCount++;
        }
        return oneCount;
    }
    
    vector<int> countBits(int n) {
        vector<int> result;
        for(int i = 0; i <= n; i++) {
            result.push_back(_getOneCount(i));
        }
        return result;
    }
};
*/