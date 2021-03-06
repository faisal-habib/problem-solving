/*
Problem:
https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
*/

class Solution{
    public:
    struct Compare {
        bool operator()(long long const &n1, long long const &n2) {
            return n1>=n2;
        }
    };
    long long minCost(long long arr[], long long n) {
        priority_queue<long long, vector<long long>, Compare>pq; // min heap
        for(int i=0; i<n; i++) pq.push(arr[i]);
        long long minCost = 0;

        while(pq.size()>1) {
            long long min, secMin;
            min = pq.top();
            pq.pop();
            secMin = pq.top();
            pq.pop();
            minCost+=(min+secMin);
            pq.push(min+secMin);
        }
        return minCost;
    }
};
