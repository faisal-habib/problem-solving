/**
Solution 1: using STL priority queue, pair
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz==k) return nums;

        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>mp;
        for(int i=0; i<sz; i++) {
            mp[nums[i]]++;
        }
        for(int i=0; i<sz; i++) {
            if(mp[nums[i]]) pq.push({mp[nums[i]], nums[i]});
            mp[nums[i]] = 0;
        }

        vector<int>out;
        while(!pq.empty()) {
            if(!k) break;
            pair<int,int>pi = pq.top();
            out.push_back(pi.second);
            k--;
            pq.pop();
        }
        return out;
    }
};
/**
Solution 2: using STL set, pair
*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int sz = nums.size();
        if(sz==k) return nums;

        set<pair<int,int>>st;
        unordered_map<int,int>mp;
        for(int i=0; i<sz; i++) {
            mp[nums[i]]++;
        }
        for(int i=0; i<sz; i++) {
            if(mp[nums[i]]) st.insert({mp[nums[i]], nums[i]});
            mp[nums[i]] = 0;
        }

        set<pair<int,int>>:: reverse_iterator it;
        vector<int>out;
        for(it=st.rbegin(); it!=st.rend(); it++) {
            if(!k) break;
            pair<int,int>pi = *it;
            out.push_back(pi.second);
            k--;
        }
        return out;
    }
};

/**
Solution 3: implementing heap
*/
