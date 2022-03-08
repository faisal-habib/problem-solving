/*
Problem link:
https://leetcode.com/problems/summary-ranges/
*/

class Solution {
public:
    string _getRange(int &leftNum, int &rightNum) {
        string output = "" ;
        output += to_string(leftNum);
        output += "->";
        output += to_string(rightNum);
        return output;
    }
    
    string _getRange(int &num) {
        string output = "" ;
        output += to_string(num);
        return output;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int sz = nums.size();
        vector<string> ranges;
        if (!sz) return ranges;
        
        for(int i = 0; i < sz; i++) {
            int j = i;
            for(j = i; j + 1 < sz; ) {
                if (nums[j] + 1 == nums[j + 1]) j++;
                else break;
            }
            if (i < j) ranges.push_back(_getRange(nums[i], nums[j]));
            else ranges.push_back(_getRange(nums[i]));
            i = j;
        }
        
        return ranges;
    }
};

/*
class Solution {
public:
    string _itoa(int &num) {
        string s = "";
        bool isNegative = false;
        
        if (num == 0) return "0";
        if (num < 0) isNegative = true, num = (-num);
        
        while(num) {
            s += ((num % 10) + '0');
            num /= 10;
        }
        
        if (isNegative) s += "-";
        reverse(s.begin(), s.end());
        
        return s;
    }
    
    string _getRange(int &leftNum, int &rightNum) {
        string output = "" ;
        output += to_string(leftNum);
        output += "->";
        output += to_string(rightNum);
        //output = _itoa(leftNum);
        //output += "->";
        //output += _itoa(rightNum);
        return output;
    }
    
    string _getRange(int &num) {
        string output = "" ;
        output += to_string(num);
        //output = _itoa(num);
        return output;
    }
    vector<string> summaryRanges(vector<int>& nums) {
        int sz = nums.size();
        vector<string> ranges;
        if (!sz) return ranges;
        
        for(int i = 0; i < sz; i++) {
            int j = i;
            for(j = i; j + 1 < sz; ) {
                if (nums[j] + 1 == nums[j + 1]) j++;
                else break;
            }
            if (i < j) ranges.push_back(_getRange(nums[i], nums[j]));
            else ranges.push_back(_getRange(nums[i]));
            i = j;
        }
        
        return ranges;
    }
};
*/