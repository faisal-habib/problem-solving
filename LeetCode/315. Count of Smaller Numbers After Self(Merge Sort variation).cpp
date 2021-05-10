/*
Problem:
https://leetcode.com/problems/count-of-smaller-numbers-after-self/
*/

class Solution {
public:
    typedef struct {
		int value, originalIndex;
	}Info;

    void _merge(vector<Info>&infoVec, vector<int>&result, int low, int mid, int high) {
        int leftId = low, rightId = mid+1, tempId = 0;
		Info temp[high-low+1];

        int rightSidedSmallerElementCount = 0;

        while( leftId<=mid && rightId<=high ) {

            if( infoVec[leftId].value > infoVec[rightId].value ) {
                rightSidedSmallerElementCount++;

                temp[tempId++] = infoVec[rightId];
                rightId++;
            }
            else {
                result[infoVec[leftId].originalIndex] += rightSidedSmallerElementCount;

                temp[tempId++] = infoVec[leftId];
                leftId++;
            }
        }

        while(leftId <= mid) {
            result[infoVec[leftId].originalIndex] += rightSidedSmallerElementCount;

            temp[tempId++] = infoVec[leftId];
            leftId++;
        }

        while(rightId <= high) {
            temp[tempId++] = infoVec[rightId];
            rightId++;
        }

        for(int i=0; i<tempId; i++) infoVec[low++] = temp[i];
    }

    void _mergeSort(vector<Info>&infoVec, vector<int>&result, int low, int high) {
        if(low < high) {
            int mid = low + (high-low)/2;
            _mergeSort(infoVec, result, low, mid);
            _mergeSort(infoVec, result,  mid+1, high);

            _merge(infoVec, result, low, mid, high);
        }
    }

    vector<int> countSmaller(vector<int>& nums) {
        int sz = nums.size();
        vector<Info>infoVec(sz);
		vector<int>result(sz);

        for(int i=0; i<sz; i++) {
			infoVec[i].value = nums[i];
			infoVec[i].originalIndex = i;
		}

        _mergeSort(infoVec, result, 0, sz-1);

        return result;
    }
};
