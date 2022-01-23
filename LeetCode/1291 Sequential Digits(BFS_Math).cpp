/*
Problem link:
https://leetcode.com/problems/sequential-digits/

Time: O (log10N)
we can go only one in direction which n * 10 + (n % 10 + 1). Which for 10^x makes it x steps, hence log10n.
n = high
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        queue<int> allNumbersQueue;
        for(int i = 1; i <= 9; i++) allNumbersQueue.push(i);
        
        while(!allNumbersQueue.empty()) {
            int currNumber = allNumbersQueue.front();
            allNumbersQueue.pop();
            
            if (currNumber > high) break;
            
            if (currNumber >= low && currNumber <= high) result.push_back(currNumber);
            
            int lastDigit = currNumber % 10;
            if (lastDigit < 9) {
                // we'll not push any number for next step which has 9 in it
                allNumbersQueue.push((currNumber * 10) + (lastDigit + 1));
            }
        }
        
        return result;
    }
};


/*
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int allNumber[] = {12,23,34,45,56,67,78,89,
                         123,234,345,456,567,678,789,
                         1234,2345,3456,4567,5678,6789,
                         12345,23456,34567,45678,56789,
                         123456,234567,345678,456789,
                         1234567,2345678,3456789,
                         12345678,23456789,
                         123456789};
        
        int allNumberArrSize = sizeof(allNumber) / sizeof(allNumber[0]);
        vector<int> result;
        for(int i = 0; i < allNumberArrSize; i++) {
            if (allNumber[i] < low) continue;
            
            if (allNumber[i] > high) break;
            
            result.push_back(allNumber[i]);
        }
        return result;
    }
};

*/