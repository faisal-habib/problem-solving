/**
Solution 1: using STL priority queue
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;   // min heap
        int sz = nums.size();
        for(int i=0; i<sz; i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};

/**
Solution 2: implementing heap
*/
class Solution {
public:
    void minHeapify(vector<int>& heap,int sz,int pos)
    {
        int l=(pos*2)+1,r=(pos*2)+2,min_value_ind=pos;

        if(l<sz && heap[l]<heap[min_value_ind]) min_value_ind=l;

        if(r<sz && heap[r]<heap[min_value_ind]) min_value_ind=r;

        if(min_value_ind!=pos)
        {
            int tmp=heap[pos];
            heap[pos]=heap[min_value_ind];
            heap[min_value_ind]=tmp;
            minHeapify(heap,sz,min_value_ind);
        }
    }

    void createMinHeapify(vector<int>& heap,int sz)
    {
        for(int i=sz/2;i>=0;i--) minHeapify(heap,sz,i);
    }

    int findKthLargest(vector<int>& nums, int k)
    {
        int sz=nums.size();

        createMinHeapify(nums,k);

        for(int i=k;i<sz;i++)
        {
            if(nums[i]>nums[0])
            {
                nums[0]=nums[i];
                minHeapify(nums,k,0);
            }
        }
        return nums[0];
    }
};
